---
title: _ITERATOR_DEBUG_LEVEL | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-standard-libraries
ms.topic: reference
f1_keywords:
- _ITERATOR_DEBUG_LEVEL
dev_langs:
- C++
helpviewer_keywords:
- _ITERATOR_DEBUG_LEVEL
ms.assetid: 718549cd-a9a9-4ab3-867b-aac00b321e67
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 4163542d0ba741e6f0a123cbdcdc44dbbec470d1
ms.sourcegitcommit: 3614b52b28c24f70d90b20d781d548ef74ef7082
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/11/2018
ms.locfileid: "38957785"
---
# <a name="iteratordebuglevel"></a>_ITERATOR_DEBUG_LEVEL

Os controles de macro iterator_debug_level se [iteradores verificados](../standard-library/checked-iterators.md) e [suporte depuração de iteradores](../standard-library/debug-iterator-support.md) estão habilitados. Essa macro substitui e combina a funcionalidade das macros secure_scl e has_iterator_debugging mais antigas.

## <a name="macro-values"></a>Valores da macro

A tabela a seguir resume os possíveis valores para a macro iterator_debug_level.

|Modo de compilação|Valor da macro|Descrição|
|----------------------|----------------|-----------------|
|**Depuração**|||
||0|Desabilita os iteradores verificados e desabilita a depuração do iterador.|
||1|Habilita os iteradores verificados e desabilita a depuração do iterador.|
||2 (padrão)|Habilita a depuração do iterador, iteradores verificados não são relevantes.|
|**Versão**|||
||0 (padrão)|Desabilita iteradores verificados.|
||1|Habilita iteradores verificados, a depuração do iterador não é revelante.|

No modo de versão, o compilador gera um erro se você especificar iterator_debug_level como 2.

## <a name="remarks"></a>Comentários

Os controles de macro iterator_debug_level se [iteradores verificados](../standard-library/checked-iterators.md) estão habilitados e, no modo de depuração, se [suporte depuração de iteradores](../standard-library/debug-iterator-support.md) está habilitado. Se iterator_debug_level for definido como 1 ou 2, os iteradores verificados garantem que os limites de seus contêineres não são substituídos. Se iterator_debug_level for 0, os iteradores não serão verificados. Quando iterator_debug_level é definido como 1, qualquer uso de iterador não seguro causa um erro de tempo de execução e o programa é encerrado. Quando iterator_debug_level é definido como 2, o iterador não seguro usar faz com que uma asserção e uma caixa de diálogo de erro de tempo de execução que permite que você entre no depurador.

Como a macro iterator_debug_level dá suporte a uma funcionalidade semelhante às macros secure_scl e has_iterator_debugging, talvez você não saiba qual macro e valor de macro usar em uma situação específica. Para evitar confusão, recomendamos que você use apenas a macro iterator_debug_level. Esta tabela descreve o valor da macro iterator_debug_level equivalente a usar para vários valores de secure_scl e has_iterator_debugging no código existente.

|**_ITERATOR_DEBUG_LEVEL** |**_SECURE_SCL** |**_HAS_ITERATOR_DEBUGGING**|
|---|---|---|
|0 (padrão da versão)|0 (desabilitado)|0 (desabilitado)|
|1|1 (habilitado)|0 (desabilitado)|
|2 (padrão da depuração)|(não relevante)|1 (habilitado no modo de depuração)|

Para obter informações sobre como desabilitar avisos sobre iteradores verificados, consulte [_SCL_SECURE_NO_WARNINGS](../standard-library/scl-secure-no-warnings.md).

### <a name="example"></a>Exemplo

Para especificar um valor para a macro iterator_debug_level, use uma [/D](../build/reference/d-preprocessor-definitions.md) opção de compilador para defini-lo na linha de comando ou use `#define` antes da biblioteca padrão C++ cabeçalhos são incluídos nos arquivos de origem. Por exemplo, na linha de comando, para compilar *Sample. cpp* no modo de depuração e usar o suporte do iterador de depuração, você pode especificar a definição da macro iterator_debug_level:

`cl /EHsc /Zi /MDd /D_ITERATOR_DEBUG_LEVEL=1 sample.cpp`

Em um arquivo de origem, especifique a macro antes de qualquer cabeçalho de biblioteca padrão que defina iteradores.

```cpp
// sample.cpp

#define _ITERATOR_DEBUG_LEVEL 1

#include <vector>

// ...
```

## <a name="see-also"></a>Consulte também

[Iteradores verificados](../standard-library/checked-iterators.md)<br/>
[Suporte ao iterador de depuração](../standard-library/debug-iterator-support.md)<br/>
[Bibliotecas seguras: Biblioteca Padrão C++](../standard-library/safe-libraries-cpp-standard-library.md)<br/>
