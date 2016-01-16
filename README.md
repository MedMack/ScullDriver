# ScullDriver

Ce repo s'agit d'un projet universitaire de développement système et logiciel où on nous a demandé d'écrire un pilote Scull sous kernel Linux.

Pour commencer, clonner le repo sur votre machine :
```
$ git clone https://github.com/MedMack/ScullDriver.git sculldriver
$ cd sculldriver
```

Le code du driver est dans le fichier `pr_char.c`. On commence par la création des modules avec cette commande :
```
$ make -C /lib/modules/$(uname -r)/build M=$PWD modules
```

Si cette étape s'est passée sans erruers on passe au lancement du pilote (le fichier `pr.char.ko` a été créé par la dernière commande ) :
```
$ sudo insmod ./pr_char.ko
``` 

Vérifier si le pilote existe dans la liste des pilotes du système en fonction :
```
cat /proc/devices
```

Vous trouverez `Project_Char_Dev` dans la liste des pilotes charactère avec un nombre majeur égal à 240. Pour tester les messages de notre pilote, il faut le donner des permissions :
```
$ sudo mknod -m 666 /dev/Projet_Char_Dev c 240 0
```

Il faut maintenant ouvrir le `syslog` pour voir les messages du pilote, pour ceci on utilise la commande suivante :
```
sudo tail -f /var/log/syslog
```

On ouvre une nouvelle fenêtre du terminal et on essaye cette commande (On garde un œil sur le premier terminal):
```
$ cat /dev/Projet_Char_Dev
```

En retournant au premier terminal, on va trouver les messages 
```
Dans la fonction pr_open
Dans la fonction pr_read
Dans la fonction pr_close
```

Pour finir, on décharge le pilote avec cette commande :
```
$ sudo insmod ./pr_char.ko
```
