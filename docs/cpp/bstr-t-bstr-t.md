---
title: _bstr_t::_bstr_t
ms.date: 11/04/2016
f1_keywords:
- _bstr_t::_bstr_t
helpviewer_keywords:
- BSTR object
- _bstr_t method [C++]
- _bstr_t class
ms.assetid: 116d994e-5a72-4351-afbe-866c80b4c165
ms.openlocfilehash: 843d6aa0e04595143d7da585e95d58e97fe80db0
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87221829"
---
# <a name="_bstr_t_bstr_t"></a>_bstr_t::_bstr_t

**Específico da Microsoft**

Constrói um objeto `_bstr_t`.

## <a name="syntax"></a>Sintaxe

```
_bstr_t( ) throw( );
_bstr_t(
   const _bstr_t& s1
) throw( );
_bstr_t(
   const char* s2
);
_bstr_t(
   const wchar_t* s3
);
_bstr_t(
   const _variant_t& var
);
_bstr_t(
   BSTR bstr,
   bool fCopy
);
```

#### <a name="parameters"></a>parâmetros

*S1*<br/>
Um objeto `_bstr_t` a ser copiado.

*S2*<br/>
Uma cadeia de caracteres multibyte.

*Estado*<br/>
Uma cadeia de caracteres Unicode

*var*<br/>
Um objeto [_variant_t](../cpp/variant-t-class.md) .

*BSTR*<br/>
Um objeto `BSTR` existente.

*fCopy*<br/>
Se **`false`** , o argumento *BSTR* será anexado ao novo objeto sem fazer uma cópia chamando `SysAllocString` .

## <a name="remarks"></a>Comentários

A tabela a seguir descreve os construtores `_bstr_t`.

|Construtor|Descrição|
|-----------------|-----------------|
|`_bstr_t( )`|Constrói um objeto padrão `_bstr_t` que encapsula um `BSTR` objeto nulo.|
|`_bstr_t( _bstr_t&`  `s1`  `)`|Constrói um objeto `_bstr_t` como uma cópia de outro.<br /><br /> Essa é uma cópia *superficial* , que incrementa a contagem de referência do objeto encapsulado `BSTR` em vez de criar um novo.|
|`_bstr_t( char*`  `s2`  `)`|Constrói um objeto `_bstr_t` chamando `SysAllocString` para criar um novo objeto `BSTR` e encapsulá-lo.<br /><br /> Esse construtor primeiro executa uma conversão de multibyte em Unicode.|
|`_bstr_t( wchar_t*`  `s3`  `)`|Constrói um objeto `_bstr_t` chamando `SysAllocString` para criar um novo objeto `BSTR` e encapsulá-lo.|
|`_bstr_t( _variant_t&`  `var`  `)`|Constrói um objeto `_bstr_t` de um objeto `_variant_t` recuperando primeiro um objeto `BSTR` do objeto VARIANT encapsulado.|
|`_bstr_t( BSTR`  `bstr` `, bool`  `fCopy`  `)`|Constrói um objeto `_bstr_t` de um `BSTR` existente (em vez de uma cadeia de caracteres `wchar_t*`). Se *fCopy* for false, o fornecido `BSTR` será anexado ao novo objeto sem fazer uma nova cópia com `SysAllocString` .<br /><br /> Esse construtor é usado por funções wrapper nos cabeçalhos da biblioteca de tipos para encapsular e assumir a propriedade de `BSTR` que é retornada por um método de interface.|

**FINAL específico da Microsoft**

## <a name="see-also"></a>Confira também

[Classe _bstr_t](../cpp/bstr-t-class.md)<br/>
[Classe _variant_t](../cpp/variant-t-class.md)
