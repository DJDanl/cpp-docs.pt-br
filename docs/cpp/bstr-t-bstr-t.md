---
title: _bstr_t::_bstr_t | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-language
ms.topic: language-reference
f1_keywords:
- _bstr_t::_bstr_t
dev_langs:
- C++
helpviewer_keywords:
- BSTR object
- _bstr_t method [C++]
- _bstr_t class
ms.assetid: 116d994e-5a72-4351-afbe-866c80b4c165
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 824108b78ede3999a83b1c7c1ac75cc847f182f5
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
ms.locfileid: "32413278"
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
 `s1`  
 Um objeto `_bstr_t` a ser copiado.  
  
 `s2`  
 Uma cadeia de caracteres multibyte.  
  
 `s3`  
 Uma cadeia de caracteres Unicode  
  
 `var`  
 Um [variant_t](../cpp/variant-t-class.md) objeto.  
  
 `bstr`  
 Um objeto `BSTR` existente.  
  
 `fCopy`  
 Se `false`, o argumento `bstr` é anexado ao novo objeto sem que uma cópia seja feita chamando `SysAllocString`.  
  
## <a name="remarks"></a>Comentários  
 A tabela a seguir descreve os construtores `_bstr_t`.  
  
|Construtor|Descrição|  
|-----------------|-----------------|  
|`_bstr_t( )`|Constrói um padrão `_bstr_t` objeto que encapsula um valor nulo `BSTR` objeto.|  
|`_bstr_t( _bstr_t&`  `s1`  `)`|Constrói um objeto `_bstr_t` como uma cópia de outro.<br /><br /> Este é um *superficial* cópia, o que incrementa a contagem de referência do encapsulada `BSTR` objeto em vez de criar um novo.|  
|`_bstr_t( char*`  `s2`  `)`|Constrói um objeto `_bstr_t` chamando `SysAllocString` para criar um novo objeto `BSTR` e encapsulá-lo.<br /><br /> Esse construtor primeiro executa uma conversão de multibyte em Unicode.|  
|`_bstr_t( wchar_t*`  `s3`  `)`|Constrói um objeto `_bstr_t` chamando `SysAllocString` para criar um novo objeto `BSTR` e encapsulá-lo.|  
|`_bstr_t( _variant_t&`  `var`  `)`|Constrói um objeto `_bstr_t` de um objeto `_variant_t` recuperando primeiro um objeto `BSTR` do objeto VARIANT encapsulado.|  
|`_bstr_t( BSTR`  `bstr` `, bool`  `fCopy`  `)`|Constrói um objeto `_bstr_t` de um `BSTR` existente (em vez de uma cadeia de caracteres `wchar_t*`). Se `fCopy` é false, o `BSTR` fornecido é anexado ao novo objeto sem que uma cópia seja feita com `SysAllocString`.<br /><br /> Esse construtor é usado por funções wrapper nos cabeçalhos da biblioteca de tipos para encapsular e assumir a propriedade de `BSTR` que é retornada por um método de interface.|  
  
 **Fim da seção específica da Microsoft**  
  
## <a name="see-also"></a>Consulte também  
 [classe bstr_t](../cpp/bstr-t-class.md)   
 [Classe _variant_t](../cpp/variant-t-class.md)