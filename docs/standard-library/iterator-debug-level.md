---
title: _ITERATOR_DEBUG_LEVEL
ms.date: 11/04/2016
f1_keywords:
- _ITERATOR_DEBUG_LEVEL
helpviewer_keywords:
- _ITERATOR_DEBUG_LEVEL
ms.assetid: 718549cd-a9a9-4ab3-867b-aac00b321e67
ms.openlocfilehash: 7b573127518969accdfdcc4a25a50269dd6aa002
ms.sourcegitcommit: 0dcab746c49f13946b0a7317fc9769130969e76d
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/24/2019
ms.locfileid: "68456397"
---
# <a name="iteratordebuglevel"></a>_ITERATOR_DEBUG_LEVEL

A macro _ITERATOR_DEBUG_LEVEL controla se os [iteradores selecionados](../standard-library/checked-iterators.md) e o [suporte ao iterador de depuração](../standard-library/debug-iterator-support.md) estão habilitados. Essa macro substitui e combina a funcionalidade das macros _SECURE_SCL e _HAS_ITERATOR_DEBUGGING mais antigas.

## <a name="macro-values"></a>Valores da macro

A tabela a seguir resume os valores possíveis para a macro _ITERATOR_DEBUG_LEVEL.

|Modo de compilação|Valor da macro|Descrição|
|----------------------|----------------|-----------------|
|**Depuração**|||
||0|Desabilita os iteradores verificados e desabilita a depuração do iterador.|
||1|Habilita os iteradores verificados e desabilita a depuração do iterador.|
||2 (padrão)|Habilita a depuração do iterador, iteradores verificados não são relevantes.|
|**Versão**|||
||0 (padrão)|Desabilita iteradores verificados.|
||1|Habilita iteradores verificados, a depuração do iterador não é revelante.|

No modo de liberação, o compilador gera um erro se você especificar _ITERATOR_DEBUG_LEVEL como 2.

## <a name="remarks"></a>Comentários

A macro _ITERATOR_DEBUG_LEVEL controla se os [iteradores marcados](../standard-library/checked-iterators.md) estão habilitados e no modo de depuração, se o [suporte ao iterador de depuração](../standard-library/debug-iterator-support.md) está habilitado. Se _ITERATOR_DEBUG_LEVEL for definido como 1 ou 2, os iteradores selecionados garantirão que os limites de seus contêineres não sejam substituídos. Se _ITERATOR_DEBUG_LEVEL for 0, os iteradores não serão verificados. Quando _ITERATOR_DEBUG_LEVEL é definido como 1, qualquer uso de iterador não seguro causa um erro de tempo de execução e o programa é encerrado. Quando _ITERATOR_DEBUG_LEVEL é definido como 2, o uso do iterador não seguro causa uma declaração e uma caixa de diálogo de erro de tempo de execução que permite que você quebre no depurador.

Como a macro _ITERATOR_DEBUG_LEVEL dá suporte à funcionalidade semelhante às macros _SECURE_SCL e _HAS_ITERATOR_DEBUGGING, você pode ter certeza de qual valor de macro e macro usar em uma situação específica. Para evitar confusão, recomendamos que você use apenas a macro _ITERATOR_DEBUG_LEVEL. Esta tabela descreve o valor de macro _ITERATOR_DEBUG_LEVEL equivalente a ser usado para vários valores de _SECURE_SCL e _HAS_ITERATOR_DEBUGGING no código existente.

|**_ITERATOR_DEBUG_LEVEL** |**_SECURE_SCL** |**_HAS_ITERATOR_DEBUGGING**|
|---|---|---|
|0 (padrão da versão)|0 (desabilitado)|0 (desabilitado)|
|1|1 (habilitado)|0 (desabilitado)|
|2 (padrão da depuração)|(não relevante)|1 (habilitado no modo de depuração)|

Para obter informações sobre como desabilitar avisos sobre iteradores verificados, consulte [_SCL_SECURE_NO_WARNINGS](../standard-library/scl-secure-no-warnings.md).

### <a name="example"></a>Exemplo

Para especificar um valor para a macro _ITERATOR_DEBUG_LEVEL, use uma opção de compilador [/d](../build/reference/d-preprocessor-definitions.md) para defini-la na linha de comando ou `#define` use antes C++ que os cabeçalhos de biblioteca padrão sejam incluídos nos arquivos de origem. Por exemplo, na linha de comando, para compilar o *Sample. cpp* no modo de depuração e usar o suporte de iterador de depuração, você pode especificar a definição de macro _ITERATOR_DEBUG_LEVEL:

`cl /EHsc /Zi /MDd /D_ITERATOR_DEBUG_LEVEL=1 sample.cpp`

Em um arquivo de origem, especifique a macro antes de qualquer cabeçalho de biblioteca padrão que defina iteradores.

```cpp
// sample.cpp

#define _ITERATOR_DEBUG_LEVEL 1

#include <vector>

// ...
```

## <a name="see-also"></a>Consulte também

[Iteradores verificados](../standard-library/checked-iterators.md)\
[Suporte ao iterador de depuração](../standard-library/debug-iterator-support.md)\
[Bibliotecas seguras: Biblioteca Padrão C++](../standard-library/safe-libraries-cpp-standard-library.md)
