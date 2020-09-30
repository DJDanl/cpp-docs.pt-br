---
title: Anotações de SAL
description: Uma breve descrição do SAL (código-fonte da nota) da Microsoft.
ms.date: 11/04/2016
ms.topic: conceptual
helpviewer_keywords:
- __z annotation
- ref annotation
- _opt annotation
- __checkreturn annotatioin
- __deref_opt annotation
- deref_opt annotation
- __deref annotation
- __in annotation
- annotations [C++]
- z annotation
- _inout annotation
- __ref annotation
- full annotation
- _in annotation
- _ref annotation
- __out annotation
- _ecount annotation
- SAL annotations
- __opt annotation
- inout annotation
- in annotation
- _CA_SHOULD_CHECK_RETURN
- __bcount annotation
- _full annotation
- _bcount annotation
- deref annotation
- part annotation
- _out annotation
- __nz annotation
- __part annotation
- opt annotation
- __full annotation
- _nz annotation
- _z annotation
- out annotation
- __ecount annotation
- __inout annotation
- SAL annotations, _CA_SHOULD_CHECK_RETURN
- _deref_opt annotation
- _deref annotation
- nz annotation
- _part annotation
- ecount annotation
- bcount annotation
ms.assetid: 81893638-010c-41a0-9cb3-666fe360f3e0
ms.openlocfilehash: 727c81ae1b141346bb47ff92b6af76d5c45aa106
ms.sourcegitcommit: 9451db8480992017c46f9d2df23fb17b503bbe74
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/30/2020
ms.locfileid: "91590258"
---
# <a name="sal-annotations"></a>Anotações de SAL

Se você examinar os arquivos de cabeçalho de biblioteca, notará algumas anotações incomuns, como por exemplo, `_In_z` e `_Out_z_cap_(_Size)`. Estes são exemplos de SAL (linguagem de anotação de código-fonte) da Microsoft, que fornece um conjunto de anotações para descrever como uma função usa seus parâmetros, por exemplo, as suposições que ela faz sobre eles e as garantias obtidas ao concluir. O arquivo de cabeçalho \<sal.h> define as anotações.

Para obter mais informações sobre como usar anotações de SAL no Visual Studio, consulte [Usando Anotações de SAL para reduzir defeitos de código C/C++](../code-quality/using-sal-annotations-to-reduce-c-cpp-code-defects.md).

## <a name="see-also"></a>Confira também

[Recursos da biblioteca CRT](../c-runtime-library/crt-library-features.md)
