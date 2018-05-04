---
title: _com_error::WCode | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-language
ms.topic: language-reference
f1_keywords:
- _com_error::WCode
dev_langs:
- C++
helpviewer_keywords:
- WCode method [C++]
ms.assetid: f3b21852-f8ea-4e43-bff1-11c2d35454c4
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 1354d490446795e55b41fa0c548e8dd8aa38c71b
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
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