---
title: Registrador da ATL e árvores de análise | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-atl
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- parse trees
ms.assetid: 668ce2dd-a1c3-4ca0-8135-b25267cb6a85
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: bb5b132e5e55ab5336254acaf4d2d3ae25440697
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
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
> `HKEY_CLASSES_ROOT` e `HKCR` forem equivalentes; `HKEY_CURRENT_USER` e `HKCU` são equivalentes; e assim por diante.  
  
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

