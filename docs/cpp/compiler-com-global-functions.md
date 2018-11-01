---
title: Funções globais COM do compilador
ms.date: 11/04/2016
helpviewer_keywords:
- cl.exe compiler, COM support
- COM, compiler support
ms.assetid: 74449d26-50a2-47c7-b175-7cf2cf83533e
ms.openlocfilehash: ac74270cd020aa66ccc14ff314a00b388a038086
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50504410"
---
# <a name="compiler-com-global-functions"></a>Funções globais COM do compilador

**Seção específica da Microsoft**

As seguintes rotinas estão disponíveis:

|Função|Descrição|
|--------------|-----------------|
|[_com_raise_error](../cpp/com-raise-error.md)|Gera uma [com_error](../cpp/com-error-class.md) em resposta a uma falha.|
|[_set_com_error_handler](../cpp/set-com-error-handler.md)|Substitui a função padrão que é usada para o tratamento de erros COM.|
|[ConvertBSTRToString](../cpp/convertbstrtostring.md)|Converte um valor `BSTR` em uma `char *`.|
|[ConvertStringToBSTR](../cpp/convertstringtobstr.md)|Converte um valor `char *` em uma `BSTR`.|

**Fim da seção específica da Microsoft**

## <a name="see-also"></a>Consulte também

[Classes de suporte COM do compilador](../cpp/compiler-com-support-classes.md)<br/>
[Suporte para COM do compilador](../cpp/compiler-com-support.md)