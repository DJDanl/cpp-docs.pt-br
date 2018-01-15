---
title: Classe messages_base | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-standard-libraries
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords: xlocmes/std::messages_base
dev_langs: C++
helpviewer_keywords: messages_base class
ms.assetid: 9aad38c6-4c13-445d-b096-364bd0836efb
caps.latest.revision: "19"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 54efcdb0b537563f46ce56f91ba5bd7805485824
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="messagesbase-class"></a>Classe messages_base
A classe base descreve um tipo `int` do catálogo de mensagens.  
  
## <a name="syntax"></a>Sintaxe  
  
```
struct messages_base : locale::facet {
    typedef int catalog;
    explicit messages_base(size_t _Refs = 0)
};
```  
  
## <a name="remarks"></a>Comentários  
 O catálogo de tipo é um sinônimo do tipo `int` que descreve os possíveis valores de retorno de messages:: [do_open](../standard-library/messages-class.md#do_open).  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** \<locale>  
  
 **Namespace:** std  
  
## <a name="see-also"></a>Consulte também  
 [Acesso Thread-Safe na Biblioteca Padrão C++](../standard-library/thread-safety-in-the-cpp-standard-library.md)



