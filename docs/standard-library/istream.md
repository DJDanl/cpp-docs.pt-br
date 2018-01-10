---
title: '&lt;istream&gt; | Microsoft Docs'
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-standard-libraries
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- istream/std::<istream>
- <istream>
- std::<istream>
dev_langs: C++
helpviewer_keywords: istream header
ms.assetid: efcf24e4-05d1-4719-ab0b-9e7ebe845d89
caps.latest.revision: "20"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 570a23dff65c6c4838d85083b25507bbf0f68e44
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
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
|[operator>>](../standard-library/istream-operators.md#op_gt_gt)|Extrai caracteres e cadeias de caracteres do fluxo.|  
  
### <a name="classes"></a>Classes  
  
|||  
|-|-|  
|[basic_iostream](../standard-library/basic-iostream-class.md)|Uma classe de fluxo que pode fazer tanto entrada quanto saída.|  
|[basic_istream](../standard-library/basic-istream-class.md)|Essa classe de modelo descreve um objeto que controla a extração de elementos e objetos codificados de um buffer de fluxo com elementos do tipo **Elem**, também conhecido como [char_type](../standard-library/basic-ios-class.md#char_type), cujas características de caractere são determinadas pela classe **Tr**, também conhecida como [traits_type](../standard-library/basic-ios-class.md#traits_type).|  
  
## <a name="see-also"></a>Consulte também  
 [Acesso Thread-Safe na Biblioteca Padrão C++](../standard-library/thread-safety-in-the-cpp-standard-library.md)   
 [Programação de iostream](../standard-library/iostream-programming.md)   
 [Convenções de iostreams](../standard-library/iostreams-conventions.md)



