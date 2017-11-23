---
title: MB_CUR_MAX | Microsoft Docs
ms.custom: 
ms.date: 10/18/2017
ms.reviewer: 
ms.suite: 
ms.technology: cpp-standard-libraries
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords: MB_CUR_MAX
dev_langs: C++
helpviewer_keywords: MB_CUR_MAX constant
ms.assetid: fab22609-c14d-4c19-991c-bd09ff30e604
caps.latest.revision: "7"
author: corob-msft
ms.author: corob
manager: ghogen
ms.openlocfilehash: 3d82463f9041e4c121fc1988f396b2a1854ff338
ms.sourcegitcommit: ca2f94dfd015e0098a6eaf5c793ec532f1c97de1
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2017
---
# <a name="mbcurmax"></a>MB_CUR_MAX

Uma macro que indica o número máximo de bytes em um caractere multibyte para a localidade atual.

## <a name="syntax"></a>Sintaxe

`#include <stdlib.h>`

## <a name="remarks"></a>Comentários

Contexto: funções de conversão de caracteres multibyte e largos ANSI

O valor de `MB_CUR_MAX` é o número máximo de bytes em um caractere multibyte para a localidade atual.

## <a name="see-also"></a>Consulte também

[_mbclen, mblen, _mblen_l](../c-runtime-library/reference/mbclen-mblen-mblen-l.md)   
[mbstowcs, _mbstowcs_l](../c-runtime-library/reference/mbstowcs-mbstowcs-l.md)   
[mbtowc, _mbtowc_l](../c-runtime-library/reference/mbtowc-mbtowc-l.md)   
[&#95;&#95;&#95;mb_cur_max_func, &#95;&#95;&#95;mb_cur_max_l_func, &#95;&#95;p&#95;&#95;&#95;mb_cur_max, &#95;&#95;mb_cur_max](../c-runtime-library/mb-cur-max-func-mb-cur-max-l-func-p-mb-cur-max-mb-cur-max.md)   
[Tipos padrão](../c-runtime-library/standard-types.md)   
[wcstombs, _wcstombs_l](../c-runtime-library/reference/wcstombs-wcstombs-l.md)   
[wctomb, _wctomb_l](../c-runtime-library/reference/wctomb-wctomb-l.md)   
[Constantes de tipo de dados](../c-runtime-library/data-type-constants.md)   
[Constantes globais](../c-runtime-library/global-constants.md)