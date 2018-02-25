---
title: '&lt;streambuf&gt; | Microsoft Docs'
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-standard-libraries
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- <streambuf>
dev_langs:
- C++
helpviewer_keywords:
- streambuf header
ms.assetid: 4365b25c-5831-488b-b9c2-867bfe961b89
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: d0b6e565c3ec7b5ea7777125c400df775c65bb1d
ms.sourcegitcommit: d51ed21ab2b434535f5c1d553b22e432073e1478
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/23/2018
---
# <a name="ltstreambufgt"></a>&lt;streambuf&gt;
Inclua o cabeçalho padrão iostreams \<streambuf> para definir a classe de modelo [basic_streambuf](../standard-library/basic-streambuf-class.md), que é básica para a operação das classes iostreams. Esse cabeçalho geralmente é incluído para você por outro cabeçalho iostreams, dificilmente você precisará incluí-lo diretamente.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
#include <streambuf>  
  
```  
  
### <a name="typedefs"></a>Typedefs  
  
|||  
|-|-|  
|[streambuf](../standard-library/streambuf-typedefs.md#streambuf)|Uma especialização de `basic_streambuf` que usa `char` como os parâmetros do modelo.|  
|[wstreambuf](../standard-library/streambuf-typedefs.md#wstreambuf)|Uma especialização de `basic_streambuf` que usa `wchar_t` como os parâmetros do modelo.|  
  
### <a name="classes"></a>Classes  
  
|||  
|-|-|  
|[Classe basic_streambuf](http://msdn.microsoft.com/en-us/d9c706ba-ce01-43e0-b0b2-a558fc53ea8d)|A classe de modelo descreve uma classe base abstrata para derivar um buffer de fluxo, que controla a transmissão de elementos de e para uma representação específica de um fluxo.|  
  
## <a name="see-also"></a>Consulte também  
 [Referência de Arquivos de Cabeçalho](../standard-library/cpp-standard-library-header-files.md)   
 [Acesso Thread-Safe na Biblioteca Padrão C++](../standard-library/thread-safety-in-the-cpp-standard-library.md)   
 [Programação de iostream](../standard-library/iostream-programming.md)   
 [Convenções de iostreams](../standard-library/iostreams-conventions.md)



