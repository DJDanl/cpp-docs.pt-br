---
title: MB_CUR_MAX | Microsoft Docs
ms.custom: ''
ms.date: 10/18/2017
ms.technology:
- cpp-standard-libraries
ms.topic: conceptual
f1_keywords:
- MB_CUR_MAX
dev_langs:
- C++
helpviewer_keywords:
- MB_CUR_MAX constant
ms.assetid: fab22609-c14d-4c19-991c-bd09ff30e604
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: e1bed389b0b52b9eaccad02c6fb59d9e89076edb
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46084543"
---
# <a name="mbcurmax"></a>MB_CUR_MAX

Uma macro que indica o número máximo de bytes em um caractere multibyte para a localidade atual.

## <a name="syntax"></a>Sintaxe

`#include <stdlib.h>`

## <a name="remarks"></a>Comentários

Contexto: funções de conversão de caracteres multibyte e largos ANSI

O valor de `MB_CUR_MAX` é o número máximo de bytes em um caractere multibyte para a localidade atual.

## <a name="see-also"></a>Consulte também

[_mbclen, mblen, _mblen_l](../c-runtime-library/reference/mbclen-mblen-mblen-l.md)<br/>
[mbstowcs, _mbstowcs_l](../c-runtime-library/reference/mbstowcs-mbstowcs-l.md)<br/>
[mbtowc, _mbtowc_l](../c-runtime-library/reference/mbtowc-mbtowc-l.md)<br/>
[&#95;&#95;&#95;mb_cur_max_func, &#95;&#95;&#95;mb_cur_max_l_func, &#95;&#95;p&#95;&#95;&#95;mb_cur_max, &#95;&#95;mb_cur_max](../c-runtime-library/mb-cur-max-func-mb-cur-max-l-func-p-mb-cur-max-mb-cur-max.md)<br/>
[Tipos padrão](../c-runtime-library/standard-types.md)<br/>
[wcstombs, _wcstombs_l](../c-runtime-library/reference/wcstombs-wcstombs-l.md)<br/>
[wctomb, _wctomb_l](../c-runtime-library/reference/wctomb-wctomb-l.md)<br/>
[Constantes de tipo de dados](../c-runtime-library/data-type-constants.md)<br/>
[Constantes globais](../c-runtime-library/global-constants.md)