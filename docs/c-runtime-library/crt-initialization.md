---
title: "Inicializa&#231;&#227;o CRT | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "inicialização CRT [C++]"
ms.assetid: e7979813-1856-4848-9639-f29c86b74ad7
caps.latest.revision: 5
caps.handback.revision: 5
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Inicializa&#231;&#227;o CRT
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Este tópico descreve como o CRT inicializa estados globais em código nativo.  
  
 Por padrão, o vinculador inclui a biblioteca de CRT, que fornece seu próprio código de inicialização.  Este código de inicialização inicializa a biblioteca de CRT, chama inicializadores globais, e depois chame fornecido pela função de `main` para aplicativos do console.  
  
## Inicializando um objeto global  
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
  
 De acordo com o padrão do C\/C\+\+, `func()` deve ser chamado antes de `main()` ser executado.  Mas que chame?  
  
 Uma maneira de determinar isso é definir um ponto de interrupção em `func()`, depurar o aplicativo, e examinar a pilha.  Isso é possível porque o código\-fonte do CRT é incluído com o Visual Studio.  
  
 Quando você procura as funções na pilha, descobrirá que o CRT estiver fazendo um loop por meio de uma lista de ponteiros da função e está chamando cada um como os encontra.  Essas funções são semelhantes a `func()` ou aos construtores para instâncias da classe.  
  
 O CRT obtém a lista de ponteiros da função do compilador do Visual C\+\+.  Quando o compilador consulta um inicializador global, gerencie um inicializador dinâmico na seção de `.CRT$XCU` \(onde `CRT` é o nome da seção e `XCU` é o nome do grupo\).  Para obter uma lista dos inicializadores dinâmicos executar o comando **dumpbin \/all main.obj**, e pesquise na seção de `.CRT$XCU` \(quando main.cpp é compilado como arquivo criando c, não arquivo c\).  Será semelhante à seguinte:  
  
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
  
 O CRT define dois ponteiros:  
  
-   `__xc_a` em `.CRT$XCA`  
  
-   `__xc_z` em `.CRT$XCZ`  
  
 Os dois grupos não têm nenhum outros símbolos definida `__xc_a` exceto e `__xc_z`.  
  
 Agora, quando o vinculador ler vários grupos de `.CRT` , os combina em uma seção e as classifica em ordem alfabética.  Isso significa que os inicializadores globais definidos pelo usuário \(que o compilador do Visual C\+\+ coloca em `.CRT$XCU`\) virão sempre `.CRT$XCA` depois de e antes de `.CRT$XCZ`.  
  
 A seção se assemelhará ao seguinte:  
  
```  
.CRT$XCA  
            __xc_a  
.CRT$XCU  
            Pointer to Global Initializer 1  
            Pointer to Global Initializer 2  
.CRT$XCZ  
            __xc_z  
```  
  
 Assim, a biblioteca de CRT usa `__xc_a` e `__xc_z` para determinar o início e o término de inicializadores globais lista devido ao modo em que são apresentados na memória depois que a imagem é carregada.  
  
## Consulte também  
 [Recursos da biblioteca CRT](../c-runtime-library/crt-library-features.md)