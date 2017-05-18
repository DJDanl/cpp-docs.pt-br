---
title: '&lt;ostream&gt; | Microsoft Docs'
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-standard-libraries
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- std.<ostream>
- <ostream>
- ostream/std::<ostream>
- std::<ostream>
dev_langs:
- C++
helpviewer_keywords:
- ostream header
ms.assetid: 90c3b6fb-57cd-4ae7-99b8-8512f24a67d2
caps.latest.revision: 20
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
ms.translationtype: Machine Translation
ms.sourcegitcommit: 66798adc96121837b4ac2dd238b9887d3c5b7eef
ms.openlocfilehash: 4b8e9c4f86ac9bab261824c10a8e6d8c3506bc1a
ms.contentlocale: pt-br
ms.lasthandoff: 04/29/2017

---
# <a name="ltostreamgt"></a>&lt;ostream&gt;
Define a classe de modelo [basic_ostream](../standard-library/basic-ostream-class.md), que atua como mediador de inserções para iostreams. O cabeçalho também define vários manipuladores relacionados. (Esse cabeçalho geralmente é incluído para você por outro cabeçalho iostreams. Raramente é necessário incluí-lo diretamente.)  
  
## <a name="syntax"></a>Sintaxe  
  
```  
#include <ostream>  
  
```  
  
### <a name="typedefs"></a>Typedefs  
  
|||  
|-|-|  
|[ostream](../standard-library/ostream-typedefs.md#ostream)|Cria um tipo de `basic_ostream` que é especializado em `char` e `char_traits` é especializado em `char`.|  
|[wostream](../standard-library/ostream-typedefs.md#wostream)|Cria um tipo de `basic_ostream` que é especializado em `wchar_t` e `char_traits` é especializado em `wchar_t`.|  
  
### <a name="manipulators"></a>Manipuladores  
  
|||  
|-|-|  
|[endl](../standard-library/ostream-functions.md#endl)|Termina uma linha e libera o buffer.|  
|[ends](../standard-library/ostream-functions.md#ends)|Termina uma cadeia de caracteres.|  
|[flush](../standard-library/ostream-functions.md#flush)|Libera o buffer.|  
|[swap](../standard-library/ostream-functions.md#swap)|Troca os valores do parâmetro de objeto `basic_ostream` à esquerda por aqueles do parâmetro de objeto `basic_ostream` à direita.|  
  
### <a name="operators"></a>Operadores  
  
|||  
|-|-|  
|[operator<<](../standard-library/ostream-operators.md#op_lt_lt)|Grava vários tipos no fluxo.|  
  
### <a name="classes"></a>Classes  
  
|||  
|-|-|  
|[basic_ostream](../standard-library/basic-ostream-class.md)|A classe de modelo descreve um objeto que controla a inserção de elementos e objetos codificados em um buffer de fluxo.|  
  
## <a name="see-also"></a>Consulte também  
 [Referência de Arquivos de Cabeçalho](../standard-library/cpp-standard-library-header-files.md)   
 [Acesso Thread-Safe na Biblioteca Padrão C++](../standard-library/thread-safety-in-the-cpp-standard-library.md)   
 [Programação de iostream](../standard-library/iostream-programming.md)   
 [Convenções de iostreams](../standard-library/iostreams-conventions.md)




