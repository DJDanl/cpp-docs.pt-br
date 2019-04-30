---
title: _com_error::WCode
ms.date: 11/04/2016
f1_keywords:
- _com_error::WCode
helpviewer_keywords:
- WCode method [C++]
ms.assetid: f3b21852-f8ea-4e43-bff1-11c2d35454c4
ms.openlocfilehash: f33871634b516723c94fead847f64ef20d25513f
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62399311"
---
# <a name="comerrorwcode"></a>_com_error::WCode

**Seção específica da Microsoft**

Recupera o código de erro de 16 bits mapeado para o HRESULT encapsulado.

## <a name="syntax"></a>Sintaxe

```
WORD WCode ( ) const throw( );
```

## <a name="return-value"></a>Valor de retorno

Se o HRESULT é dentro do intervalo 0x80040200 a 0x8004FFFF, o `WCode` método retornará o HRESULT menos 0x80040200; caso contrário, retornará zero.

## <a name="remarks"></a>Comentários

O `WCode` método é usado para desfazer um mapeamento que acontece no código de suporte COM. O wrapper para um `dispinterface` propriedade ou método chama uma rotina de suporte que empacota os argumentos e as chamadas `IDispatch::Invoke`. No retorno, se uma falha HRESULT de `DISP_E_EXCEPTION` for retornado, as informações de erro são recuperadas do `EXCEPINFO` estrutura passada para `IDispatch::Invoke`. O código de erro pode ser um valor de 16 bits armazenado na `wCode` membro do `EXCEPINFO` estrutura ou um valor de 32 bits completo na `scode` membro do `EXCEPINFO` estrutura. Se, de 16 bits `wCode` for retornado, ele primeiro deve ser mapeado para uma HRESULT de falha de 32 bits.

**Fim da seção específica da Microsoft**

## <a name="see-also"></a>Consulte também

[_com_error::HRESULTToWCode](../cpp/com-error-hresulttowcode.md)<br/>
[_com_error::WCodeToHRESULT](../cpp/com-error-wcodetohresult.md)<br/>
[Classe _com_error](../cpp/com-error-class.md)