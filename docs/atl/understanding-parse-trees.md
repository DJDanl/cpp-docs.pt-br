---
title: "Entender analisa &#225;rvores | Microsoft Docs"
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
  - "analisar árvores"
ms.assetid: 668ce2dd-a1c3-4ca0-8135-b25267cb6a85
caps.latest.revision: 12
caps.handback.revision: 7
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Entender analisa &#225;rvores
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Você pode definir um ou mais analisa árvores no script de escrivão, onde cada analisar a árvore tem a seguinte forma:  
  
```  
<root key>{<registry expression>}+  
```  
  
 onde:  
  
```  
<root key> ::=  HKEY_CLASSES_ROOT | HKEY_CURRENT_USER |  
               HKEY_LOCAL_MACHINE | HKEY_USERS |  
               HKEY_PERFORMANCE_DATA | HKEY_DYN_DATA |  
               HKEY_CURRENT_CONFIG | HKCR | HKCU |  
               HKLM | HKU | HKPD | HKDD | HKCC  
<registry expression> ::= <Add Key> | <Delete Key>  
<Add Key> ::= [ForceRemove | NoRemove | val]<Key Name>  
              [<Key Value>][{< Add Key>}]  
<Delete Key> ::=  Delete<Key Name>  
<Key Name> ::= '<AlphaNumeric>+'  
<AlphaNumeric> ::= any character not NULL, i.e. ASCII 0  
<Key Value> ::== <Key Type><Key Name>  
<Key Type> ::= s | d  
<Key Value> ::= '<AlphaNumeric>'  
```  
  
> [!NOTE]
>  `HKEY_CLASSES_ROOT` e `HKCR` são equivalentes; `HKEY_CURRENT_USER` e `HKCU` são equivalentes; e assim por diante.  
  
 Uma árvore de análise pode adicionar várias chaves e subchaves a \<root key\>.  Para fazê\-lo, mantém a alça de uma subchave aberta até que o analisador conclua o analisar todas as suas subchaves.  Essa abordagem é mais eficiente do que operando\-se em uma única chave em vez, como visto no exemplo a seguir:  
  
```  
HKEY_CLASSES_ROOT  
{  
   'MyVeryOwnKey'  
   {  
      'HasASubKey'  
      {  
         'PrettyCool?'  
      }  
   }  
}  
```  
  
 Aqui, o escrivão inicialmente abre \(cria\) `HKEY_CLASSES_ROOT\MyVeryOwnKey`.  Em seguida `MyVeryOwnKey` que tem uma subchave.  Em vez de fecha a chave para `MyVeryOwnKey`, o escrivão retém o identificador e abre \(cria\) `HasASubKey` usando este identificador pai.  \(O Registro do sistema pode ser mais lento quando nenhuma alça pai estiver aberta.\) Assim, abra `HKEY_CLASSES_ROOT\MyVeryOwnKey` e então abra `HasASubKey` com `MyVeryOwnKey` como o pai são mais rápidas de abrir, fechar `MyVeryOwnKey``MyVeryOwnKey`e em seguida, abrindo `MyVeryOwnKey\HasASubKey`.  
  
## Consulte também  
 [Criando scripts de escrivão](../Topic/Creating%20Registrar%20Scripts.md)