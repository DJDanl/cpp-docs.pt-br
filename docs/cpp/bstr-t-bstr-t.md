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
ms.openlocfilehash: 70678b0be8b25bf3ee883630caa26598e5e31089
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50450040"
---
# <a name="bstrtbstrt"></a>_bstr_t::_bstr_t

**Seção específica da Microsoft**

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

#### <a name="parameters"></a>Parâmetros

*S1*<br/>
Um objeto `_bstr_t` a ser copiado.

*S2*<br/>
Uma cadeia de caracteres multibyte.

*S3*<br/>
Uma cadeia de caracteres Unicode

*var*<br/>
Um [variant_t](../cpp/variant-t-class.md) objeto.

*BSTR*<br/>
Um objeto `BSTR` existente.

*fCopy*<br/>
Se for FALSE, o *bstr* argumento é anexado ao novo objeto sem fazer uma cópia chamando `SysAllocString`.

## <a name="remarks"></a>Comentários

A tabela a seguir descreve os construtores `_bstr_t`.

|Construtor|Descrição|
|-----------------|-----------------|
|`_bstr_t( )`|Constrói um padrão `_bstr_t` objeto que encapsula um valor nulo `BSTR` objeto.|
|`_bstr_t( _bstr_t&`  `s1`  `)`|Constrói um objeto `_bstr_t` como uma cópia de outro.<br /><br /> Esse é um *superficial* cópia, o que incrementa a contagem de referência de encapsulado `BSTR` objeto em vez de criar um novo.|
|`_bstr_t( char*`  `s2`  `)`|Constrói um objeto `_bstr_t` chamando `SysAllocString` para criar um novo objeto `BSTR` e encapsulá-lo.<br /><br /> Esse construtor primeiro executa uma conversão de multibyte em Unicode.|
|`_bstr_t( wchar_t*`  `s3`  `)`|Constrói um objeto `_bstr_t` chamando `SysAllocString` para criar um novo objeto `BSTR` e encapsulá-lo.|
|`_bstr_t( _variant_t&`  `var`  `)`|Constrói um objeto `_bstr_t` de um objeto `_variant_t` recuperando primeiro um objeto `BSTR` do objeto VARIANT encapsulado.|
|`_bstr_t( BSTR`  `bstr` `, bool`  `fCopy`  `)`|Constrói um objeto `_bstr_t` de um `BSTR` existente (em vez de uma cadeia de caracteres `wchar_t*`). Se *fCopy* é false, fornecido `BSTR` é anexado ao novo objeto sem que uma nova cópia com `SysAllocString`.<br /><br /> Esse construtor é usado por funções wrapper nos cabeçalhos da biblioteca de tipos para encapsular e assumir a propriedade de `BSTR` que é retornada por um método de interface.|

**Fim da seção específica da Microsoft**

## <a name="see-also"></a>Consulte também

[Classe _bstr_t](../cpp/bstr-t-class.md)<br/>
[Classe _variant_t](../cpp/variant-t-class.md)