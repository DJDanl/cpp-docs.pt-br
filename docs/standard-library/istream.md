---
title: '&lt;istream&gt; | Microsoft Docs'
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- istream/std::<istream>
- std.<istream>
- <istream>
- std::<istream>
dev_langs:
- C++
helpviewer_keywords:
- istream header
ms.assetid: efcf24e4-05d1-4719-ab0b-9e7ebe845d89
caps.latest.revision: 20
author: corob-msft
ms.author: corob
manager: ghogen
translation.priority.mt:
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
translationtype: Machine Translation
ms.sourcegitcommit: 3168772cbb7e8127523bc2fc2da5cc9b4f59beb8
ms.openlocfilehash: 590dcefb4804e50197e945bea6c39e2bd4e1e15a
ms.lasthandoff: 02/25/2017

---
# <a name="ltistreamgt"></a>&lt;istream&gt;
Define a classe de modelo basic_istream, que atua como mediador de extrações para os iostreams e a classe de modelo basic_iostream, que atua como mediador de extrações e inserções. O cabeçalho também define um manipulador relacionado. Esse arquivo de cabeçalho geralmente é incluído para você por outro cabeçalho iostreams, dificilmente você precisará incluí-lo diretamente.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
#include <istream>  
  
```  
  
### <a name="typedefs"></a>Typedefs  
  
|||  
|-|-|  
|[iostream](../standard-library/istream-typedefs.md#iostream)|Um tipo `basic_iostream` especializado em `char`.|  
|[istream](../standard-library/istream-typedefs.md#istream)|Um tipo `basic_istream` especializado em `char`.|  
|[wiostream](../standard-library/istream-typedefs.md#wiostream)|Um tipo `basic_iostream` especializado em **wchar**.|  
|[wistream](../standard-library/istream-typedefs.md#wistream)|Um tipo `basic_istream` especializado em **wchar**.|  
  
### <a name="manipulators"></a>Manipuladores  
  
|||  
|-|-|  
|[ws](../standard-library/istream-functions.md#ws)|Ignora o espaço em branco no fluxo.|  
|[swap](../standard-library/istream-functions.md#istream_swap)|Troca dois objetos de fluxo.|  
  
### <a name="operators"></a>Operadores  
  
|||  
|-|-|  
|[operator>>](../standard-library/istream-operators.md#operator_gt__gt_)|Extrai caracteres e cadeias de caracteres do fluxo.|  
  
### <a name="classes"></a>Classes  
  
|||  
|-|-|  
|[basic_iostream](../standard-library/basic-iostream-class.md)|Uma classe de fluxo que pode fazer tanto entrada quanto saída.|  
|[basic_istream](../standard-library/basic-istream-class.md)|Essa classe de modelo descreve um objeto que controla a extração de elementos e objetos codificados de um buffer de fluxo com elementos do tipo **Elem**, também conhecido como [char_type](../standard-library/basic-ios-class.md#basic_ios__char_type), cujas características de caractere são determinadas pela classe **Tr**, também conhecida como [traits_type](../standard-library/basic-ios-class.md#basic_ios__traits_type).|  
  
## <a name="see-also"></a>Consulte também  
 [Acesso Thread-Safe na Biblioteca Padrão C++](../standard-library/thread-safety-in-the-cpp-standard-library.md)   
 [Programação de iostream](../standard-library/iostream-programming.md)   
 [Convenções de iostreams](../standard-library/iostreams-conventions.md)




