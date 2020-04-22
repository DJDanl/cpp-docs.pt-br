---
title: _com_raise_error
ms.date: 11/04/2016
f1_keywords:
- _com_raise_error
helpviewer_keywords:
- _com_raise_error function
ms.assetid: a98226c2-c3fe-44f1-8ff5-85863de11cd6
ms.openlocfilehash: f5efbe98a489a380c4e9be5a0e40603be2a409c0
ms.sourcegitcommit: 7a6116e48c3c11b97371b8ae4ecc23adce1f092d
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/22/2020
ms.locfileid: "81745087"
---
# <a name="_com_raise_error"></a>_com_raise_error

**Específico da Microsoft**

Lança um [_com_error](../cpp/com-error-class.md) em resposta a uma falha.

## <a name="syntax"></a>Sintaxe

```cpp
void __stdcall _com_raise_error(
   HRESULT hr,
   IErrorInfo* perrinfo = 0
);
```

#### <a name="parameters"></a>Parâmetros

*Hr*<br/>
Informações do HRESULT.

*perrinfo*<br/>
Objeto `IErrorInfo`.

## <a name="remarks"></a>Comentários

**_com_raise_error**, que \<é definido em comdef.h>, pode ser substituído por uma versão escrita pelo usuário com o mesmo nome e protótipo. Isso poderia ser feito se você quisesse usar `#import`, mas não quisesse usar ao tratamento de exceções do C++. Nesse caso, uma versão **_com_raise_error** do usuário do `longjmp` _com_raise_error pode decidir fazer uma ou exibir uma caixa de mensagem e parar. No entanto, a versão do usuário não deve retornar, pois o código de suporte do compilador COM não espera que ela retorne.

Você também pode usar [_set_com_error_handler](../cpp/set-com-error-handler.md) para substituir a função padrão de manipulação de erros.

Por padrão, **_com_raise_error** é definido da seguinte forma:

```cpp
void __stdcall _com_raise_error(HRESULT hr, IErrorInfo* perrinfo) {
   throw _com_error(hr, perrinfo);
}
```

**Fim específico da Microsoft**

## <a name="requirements"></a>Requisitos

**Cabeçalho:** \<comdef.h>

**Lib:** Se a opção de compilador **de tipo nativo wchar_t** estiver ativada, use comsuppw.lib ou comsuppwd.lib. Se **wchar_t é Tipo Nativo** está desligado, use comsupp.lib. Para obter mais informações, consulte [/Zc:wchar_t (wchar_t é o tipo nativo)](../build/reference/zc-wchar-t-wchar-t-is-native-type.md).

## <a name="see-also"></a>Confira também

[Funções globais COM do compilador](../cpp/compiler-com-global-functions.md)<br/>
[_set_com_error_handler](../cpp/set-com-error-handler.md)
