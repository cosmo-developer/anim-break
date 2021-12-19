import os
import sys
import json
from easygui import enterbox,fileopenbox

EASY_GIT_CONFIG_TITLE="EasyGit Config Window"

def choose_system(field,field_type,mode,defaultval):

    if defaultval is None:
        defaultval=""
    
    if field_type == 'media/text':
        if mode == 'gui':
            return enterbox(f"Enter {field}",EASY_GIT_CONFIG_TITLE,defaultval)
        elif mode == 'cui':
            return input(f"Enter {field}"+f"({defaultval}):" if len(defaultval)>0 else ":")
    elif field_type == 'media/file':
        if mode == 'gui':
            return fileopenbox()
        elif mode == 'cui':
            work=f"Enter {field}"
            if len(defaultval) > 0:
                work+=f"({defaultval})"
            return input(work+":")

def configuration_system(field,field_type,ask_mode,mode,defaultval):
    if ask_mode == 'on':
        return {f"{field}":choose_system(field,field_type,mode,defaultval)}
    elif ask_mode == 'off':
        return {f"{field}":defaultval}
        

easy_git_config_file=open('easygitconfig.json')
easy_git_config_data=json.load(easy_git_config_file)['EasyGitConfigData']
easy_git_config_file.close()



KEY_PATH=configuration_system(
    'gpg_key_path',
    easy_git_config_data['gpg_key_path']['dtype'],
    easy_git_config_data['gpg_key_path']['ask'],
    easy_git_config_data['gpg_key_path']['mode'],
    easy_git_config_data['gpg_key_path']['value']
    )['gpg_key_path']

USERNAME=configuration_system(
    'user-name',
    easy_git_config_data['user-name']['dtype'],
    easy_git_config_data['user-name']['ask'],
    easy_git_config_data['user-name']['mode'],
    easy_git_config_data['user-name']['value']
    )['user-name']

REPOSITORY=configuration_system(
    'repository',
    easy_git_config_data['repository']['dtype'],
    easy_git_config_data['repository']['ask'],
    easy_git_config_data['repository']['mode'],
    easy_git_config_data['repository']['value']
    )['repository']

gpg_key_file=open(KEY_PATH)
gpg_key_data=gpg_key_file.read()
gpg_key_file.close()

args=sys.argv

def show_list_command():
    print("easygit.py --help")
    print("easygit.py {push|fetch|pull}")

def show_print_help(command=None):
    if command:
        print(f"Invalid Command [easygit.py {command}]")
        show_list_command()
    else:
        show_list_command()

class GitCommandError(Exception):
    def __init__(self,msg):
        self.msg=msg
    def __str__(self):
        return str(self.msg)

def fire_command(command):
    ret_code=os.system(f"git {command} https://{USERNAME}:{gpg_key_data}@github.com/{USERNAME}/{REPOSITORY}.git")
    if ret_code != 0:
        raise GitCommandError(f"Git Command Failure Occurs while using {command}")

if len(args) < 2:
    args.append(input("enter {push|fetch|pull}:"))
    fire_command(args[1])
elif args[1] == "--help":
    show_list_command()
elif args[1] == "push":
    fire_command(args[1])
elif args[1] == "pull":
    fire_command(args[1])
elif args[1] == "fetch":
    fire_command(args[1])
else:
    show_print_help(args[1])

input("Press enter to exit")
