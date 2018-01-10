---
title: "Registrador da ATL e árvores de análise | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
helpviewer_keywords: parse trees
ms.assetid: 668ce2dd-a1c3-4ca0-8135-b25267cb6a85
caps.latest.revision: "12"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: c8ce648a541f6e0e2d4fac2e6ee19226e41f20ad
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="understanding-parse-trees"></a>Noções básicas sobre árvores de análise
Você pode definir uma ou mais árvores de análise no seu script de registrador, onde cada árvore de análise tem a seguinte forma:  
  
```  
<root key>{<registry expression>}+  
```  
  
 em que:  
  
```  
<root key> ::= HKEY_CLASSES_ROOT | HKEY_CURRENT_USER |  
    HKEY_LOCAL_MACHINE | HKEY_USERS |  
    HKEY_PERFORMANCE_DATA | HKEY_DYN_DATA |  
    HKEY_CURRENT_CONFIG | HKCR | HKCU |  
    HKLM | HKU | HKPD | HKDD | HKCC  
<registry expression> ::= <Add Key> | <Delete Key>  
<Add Key> ::= [ForceRemove | NoRemove | val]<Key Name>  
 [<Key Value>][{<Add Key>}]  
<Delete Key> ::= Delete<Key Name>  
<Key Name> ::= '<AlphaNumeric>+'  
<AlphaNumeric> ::= any character not NULL, i.e. ASCII 0  
<Key Value> ::== <Key Type><Key Name>  
<Key Type> ::= s | d  
<Key Value> ::= '<AlphaNumeric>'  
```  
  
> [!NOTE]
> `HKEY_CLASSES_ROOT`e `HKCR` forem equivalentes; `HKEY_CURRENT_USER` e `HKCU` são equivalentes; e assim por diante.  
  
 Uma árvore de análise pode adicionar várias chaves e subchaves para a \<chave raiz >. Dessa forma, ele mantém identificador da subchave aberto até que o analisador concluiu a análise de todas as suas subchaves. Essa abordagem é mais eficiente do que a operação em uma única chave ao mesmo tempo, como mostrado no exemplo a seguir:  
  
```  
HKEY_CLASSES_ROOT  
{  
 'MyVeryOwnKey'  
 {  
 'HasASubKey'  
 {  
 'PrettyCool'  
 }  
 }  
}  
```  
  
 Aqui, o registrador inicialmente abre (cria) `HKEY_CLASSES_ROOT\MyVeryOwnKey`. Em seguida, vê que `MyVeryOwnKey` tem uma subchave. Em vez de fechar a chave para `MyVeryOwnKey`, o registrador retém o identificador e abre (cria) `HasASubKey` usando o identificador do pai. (O registro do sistema pode ser mais lento quando nenhum identificador pai está aberto.) Assim, abrindo `HKEY_CLASSES_ROOT\MyVeryOwnKey` e abrindo `HasASubKey` com `MyVeryOwnKey` como o pai é mais rápido do que abrir `MyVeryOwnKey`, fechando `MyVeryOwnKey`e, em seguida, abrir `MyVeryOwnKey\HasASubKey`.  
  
## <a name="see-also"></a>Consulte também  
 [Criando scripts do Registrador](../atl/creating-registrar-scripts.md)

