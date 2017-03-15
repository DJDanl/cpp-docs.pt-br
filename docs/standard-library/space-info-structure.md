---
title: Estrutura space_info | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- filesystem/std::tr2::sys::space_info
dev_langs:
- C++
ms.assetid: f2b35b42-06ff-45bd-8617-39a0f5358a54
caps.latest.revision: 13
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
ms.openlocfilehash: 77314d99a34f109e556b8583b06ce51acce288bc
ms.lasthandoff: 02/25/2017

---
# <a name="spaceinfo-structure"></a>Estrutura space_info
Mantém informações sobre um volume.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
struct space_info    {
    uintmax_t capacity;
    uintmax_t free;
    uintmax_t available;
    };  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-data-members"></a>Membros de Dados Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|`unsigned long long available`|Representa o número de bytes que estão disponíveis para representar os dados no volume.|  
|`unsigned long long capacity`|Representa o número total de bytes que o volume pode representar.|  
|`unsigned long long free`|Representa o número de bytes que não são usados para representar os dados no volume.|  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** filesystem  
  
 **Namespace:** std::experimental::filesystem  
  
## <a name="see-also"></a>Consulte também  
 [Referência de Arquivos de Cabeçalho](../standard-library/cpp-standard-library-header-files.md)   
 [\<filesystem>](../standard-library/filesystem.md)   
 [Função space](http://msdn.microsoft.com/en-us/7fce0b0e-523b-4598-b218-47245d0204ca)   
 [Navegação no sistema de arquivos (C++)](../standard-library/file-system-navigation.md)


