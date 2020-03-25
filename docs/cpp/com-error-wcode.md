---
title: _com_error::WCode
ms.date: 11/04/2016
f1_keywords:
- _com_error::WCode
helpviewer_keywords:
- WCode method [C++]
ms.assetid: f3b21852-f8ea-4e43-bff1-11c2d35454c4
ms.openlocfilehash: 92dffbdbe034ef55be04c1b7d204be6880d8d4b2
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80190190"
---
# <a name="_com_errorwcode"></a>_com_error::WCode

**Seção específica da Microsoft**

Recupera o código de erro de 16 bits mapeado para o HRESULT encapsulado.

## <a name="syntax"></a>Sintaxe

```
WORD WCode ( ) const throw( );
```

## <a name="return-value"></a>Valor retornado

Se o HRESULT estiver dentro do intervalo de 0x80040200 a 0x8004FFFF, o método `WCode` retornará o HRESULT menos 0x80040200; caso contrário, retornará zero.

## <a name="remarks"></a>Comentários

O método `WCode` é usado para desfazer um mapeamento que ocorre no código de suporte COM. O wrapper de uma `dispinterface` propriedade ou método chama uma rotina de suporte que empacota os argumentos e chamadas `IDispatch::Invoke`. No retorno, se um HRESULT de falha de `DISP_E_EXCEPTION` for retornado, as informações de erro serão recuperadas da estrutura de `EXCEPINFO` passada para `IDispatch::Invoke`. O código de erro pode ser um valor de 16 bits armazenado no membro de `wCode` da estrutura de `EXCEPINFO` ou um valor de 32 bits completo no membro `scode` da estrutura de `EXCEPINFO`. Se um `wCode` de 16 bits for retornado, ele deverá primeiro ser mapeado para um HRESULT de falha de 32 bits.

**Fim da seção específica da Microsoft**

## <a name="see-also"></a>Confira também

[_com_error::HRESULTToWCode](../cpp/com-error-hresulttowcode.md)<br/>
[_com_error::WCodeToHRESULT](../cpp/com-error-wcodetohresult.md)<br/>
[Classe _com_error](../cpp/com-error-class.md)
