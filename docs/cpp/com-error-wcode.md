---
title: _com_error::WCode | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-language
ms.tgt_pltfrm: 
ms.topic: language-reference
f1_keywords:
- _com_error.WCode
- _com_error::WCode
- WCode
dev_langs:
- C++
helpviewer_keywords:
- WCode method
ms.assetid: f3b21852-f8ea-4e43-bff1-11c2d35454c4
caps.latest.revision: 6
author: mikeblome
ms.author: mblome
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
ms.translationtype: HT
ms.sourcegitcommit: 6ffef5f51e57cf36d5984bfc43d023abc8bc5c62
ms.openlocfilehash: 15c0d860a5faffc160def725630fbbb1d84d8ed8
ms.contentlocale: pt-br
ms.lasthandoff: 09/25/2017

---
# <a name="comerrorwcode"></a>_com_error::WCode
**Seção específica da Microsoft**  
  
 Recupera o código de erro de 16 bits mapeado para o `HRESULT` encapsulado.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
  
WORD WCode ( ) const throw( );  
  
```  
  
## <a name="return-value"></a>Valor de retorno  
 Se o `HRESULT` está dentro do intervalo 0x80040200 para 0x8004FFFF o **WCode** método retorna o `HRESULT` menos 0x80040200; caso contrário, retorna zero.  
  
## <a name="remarks"></a>Comentários  
 O **WCode** método é usado para desfazer um mapeamento que ocorre no código COM suporte. O wrapper para um **dispinterface** propriedade ou método chama uma rotina de suporte que empacota os argumentos e as chamadas **IDispatch:: Invoke**. No retorno, no caso de falha de `HRESULT` de `DISP_E_EXCEPTION` for retornado, as informações de erro são recuperadas do **EXCEPINFO** estrutura passado para **IDispatch:: Invoke**. O código de erro pode ser um valor de 16 bits armazenado no `wCode` membro do **EXCEPINFO** estrutura ou um valor de 32 bits completa no **scode** membro do **EXCEPINFO**estrutura. Se `wCode` de 16 bits for retornado, deve primeiramente ser mapeado para uma falha de 32 bits `HRESULT`.  
  
 **Fim da seção específica da Microsoft**  
  
## <a name="see-also"></a>Consulte também  
 [_com_error::HRESULTToWCode](../cpp/com-error-hresulttowcode.md)   
 [_com_error::WCodeToHRESULT](../cpp/com-error-wcodetohresult.md)   
 [Classe _com_error](../cpp/com-error-class.md)
