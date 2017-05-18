---
title: "Inicialização CRT | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-standard-libraries
ms.tgt_pltfrm: 
ms.topic: article
dev_langs:
- C++
helpviewer_keywords:
- CRT initialization [C++]
ms.assetid: e7979813-1856-4848-9639-f29c86b74ad7
caps.latest.revision: 5
author: corob-msft
ms.author: corob
manager: ghogen
translation.priority.ht:
- cs-cz
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- pl-pl
- pt-br
- ru-ru
- tr-tr
- zh-cn
- zh-tw
ms.translationtype: Human Translation
ms.sourcegitcommit: 3168772cbb7e8127523bc2fc2da5cc9b4f59beb8
ms.openlocfilehash: 593dad6bf8d80ccc588a11c59fd737b55ae798c4
ms.contentlocale: pt-br
ms.lasthandoff: 02/25/2017

---
# <a name="crt-initialization"></a>Inicialização CRT
Este tópico descreve como o CRT inicializa estados globais em código nativo.  
  
 Por padrão, o vinculador inclui a biblioteca CRT, que fornece seu próprio código de inicialização. Esse código de inicialização inicializa a biblioteca CRT, chama inicializadores globais e, em seguida, chama a função `main` fornecida pelo usuário para aplicativos de console.  
  
## <a name="initializing-a-global-object"></a>Inicializando um objeto global  
 Considere o código a seguir:  
  
```  
int func(void)  
{  
    return 3;  
}  
  
int gi = func();  
  
int main()  
{  
    return gi;  
}  
```  
  
 Segundo o padrão C/C++, `func()` deve ser chamado antes que `main()` seja executado. Mas, quem chama?  
  
 Uma maneira de determinar isso é definir um ponto de interrupção em `func()`, depurar o aplicativo e examinar a pilha. Isso é possível porque o código-fonte CRT está incluído no Visual Studio.  
  
 Quando procura as funções na pilha, você encontra o que o CRT está em loop através de uma lista de ponteiros de função e chamar cada um ao encontrá-los. Essas funções são semelhantes a `func()` ou construtores de instâncias de classe.  
  
 A CRT obtém a lista de ponteiros de função do compilador do Visual C++. Quando o compilador vê um inicializador global, ele gera um inicializador dinâmico na seção `.CRT$XCU` (em que `CRT` é o nome da seção e `XCU` é o nome do grupo). Para obter uma lista dos inicializadores dinâmicos, execute o comando **dumpbin/all main.obj** e, em seguida, procure a seção `.CRT$XCU` (quando main.cpp é compilado como arquivo C++, e não como arquivo C). Ele será semelhante ao seguinte:  
  
```  
SECTION HEADER #6  
.CRT$XCU name  
       0 physical address  
       0 virtual address  
       4 size of raw data  
     1F2 file pointer to raw data (000001F2 to 000001F5)  
     1F6 file pointer to relocation table  
       0 file pointer to line numbers  
       1 number of relocations  
       0 number of line numbers  
40300040 flags  
         Initialized Data  
         4 byte align  
         Read Only  
  
RAW DATA #6  
  00000000: 00 00 00 00                                      ....  
  
RELOCATIONS #6  
                                                Symbol    Symbol  
 Offset    Type              Applied To         Index     Name  
 --------  ----------------  -----------------  --------  ------  
 00000000  DIR32                      00000000         C  ??__Egi@@YAXXZ (void __cdecl `dynamic initializer for 'gi''(void))  
```  
  
 A CRT define dois ponteiros:  
  
-   `__xc_a` in `.CRT$XCA`  
  
-   `__xc_z` in `.CRT$XCZ`  
  
 Ambos os grupos não têm outros símbolos definidos, apenas `__xc_a` e `__xc_z`.  
  
 Agora, quando lê vários grupos `.CRT`, o vinculador os combina em uma seção e os classifica em ordem alfabética. Isso significa que os inicializadores globais definidos pelo usuário (que o compilador C++ do Visual coloca em `.CRT$XCU`) sempre virão depois de `.CRT$XCA` e antes de `.CRT$XCZ`.  
  
 A seção será semelhante ao que segue:  
  
```  
.CRT$XCA  
            __xc_a  
.CRT$XCU  
            Pointer to Global Initializer 1  
            Pointer to Global Initializer 2  
.CRT$XCZ  
            __xc_z  
```  
  
 Portanto, a biblioteca CRT usa `__xc_a` e `__xc_z` para determinar o início e fim da lista de inicializadores global devido à forma como são dispostos na memória depois que a imagem é carregada.  
  
## <a name="see-also"></a>Consulte também  
 [Recursos da biblioteca CRT](../c-runtime-library/crt-library-features.md)
