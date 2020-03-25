---
title: _com_raise_error
ms.date: 11/04/2016
f1_keywords:
- _com_raise_error
helpviewer_keywords:
- _com_raise_error function
ms.assetid: a98226c2-c3fe-44f1-8ff5-85863de11cd6
ms.openlocfilehash: 2012ec98d8d40d60a7f12feb68bdc371e1616223
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80189787"
---
# <a name="_com_raise_error"></a>_com_raise_error

**Seção específica da Microsoft**

Gera um [_com_error](../cpp/com-error-class.md) em resposta a uma falha.

## <a name="syntax"></a>Sintaxe

```
void __stdcall _com_raise_error(
   HRESULT hr,
   IErrorInfo* perrinfo = 0
);
```

#### <a name="parameters"></a>parâmetros

*Human*<br/>
Informações de HRESULT.

*perrinfo*<br/>
Objeto `IErrorInfo`.

## <a name="remarks"></a>Comentários

**_com_raise_error**, que é definido no \<comdef. h >, pode ser substituído por uma versão escrita pelo usuário com o mesmo nome e protótipo. Isso poderia ser feito se você quisesse usar `#import`, mas não quisesse usar ao tratamento de exceções do C++. Nesse caso, uma versão de usuário do **_com_raise_error** pode decidir fazer uma `longjmp` ou exibir uma caixa de mensagem e parar. No entanto, a versão do usuário não deve retornar, pois o código de suporte do compilador COM não espera que ela retorne.

Você também pode usar [_set_com_error_handler](../cpp/set-com-error-handler.md) para substituir a função de tratamento de erros padrão.

Por padrão, **_com_raise_error** é definido da seguinte maneira:

```cpp
void __stdcall _com_raise_error(HRESULT hr, IErrorInfo* perrinfo) {
   throw _com_error(hr, perrinfo);
}
```

**Fim da seção específica da Microsoft**

## <a name="requirements"></a>Requisitos

**Cabeçalho:** \<comdef. h >

**Lib:** Se o wchar_t opção de compilador de **tipo nativo** estiver ativado, use comsuppw. lib ou comsuppwd. lib. Se **Wchar_t tipo nativo** for off, use comsupp. lib. Para obter mais informações, consulte [/Zc:wchar_t (wchar_t é o tipo nativo)](../build/reference/zc-wchar-t-wchar-t-is-native-type.md).

## <a name="see-also"></a>Confira também

[Funções globais COM do compilador](../cpp/compiler-com-global-functions.md)<br/>
[_set_com_error_handler](../cpp/set-com-error-handler.md)
