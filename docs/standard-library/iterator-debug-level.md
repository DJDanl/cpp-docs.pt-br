---
title: _ITERATOR_DEBUG_LEVEL | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.reviewer: ''
ms.suite: ''
ms.technology:
- cpp-standard-libraries
ms.tgt_pltfrm: ''
ms.topic: reference
f1_keywords:
- _ITERATOR_DEBUG_LEVEL
dev_langs:
- C++
helpviewer_keywords:
- _ITERATOR_DEBUG_LEVEL
ms.assetid: 718549cd-a9a9-4ab3-867b-aac00b321e67
caps.latest.revision: 6
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 3b317358a00879d4430b94ea29ab547761044e56
ms.sourcegitcommit: dd1a509526fa8bb18e97ab7bc7b91cbdb3ec7059
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/26/2018
---
# <a name="iteratordebuglevel"></a>_ITERATOR_DEBUG_LEVEL

A macro `_ITERATOR_DEBUG_LEVEL` controla se [iteradores verificados](../standard-library/checked-iterators.md) e o [suporte depuração de iteradores](../standard-library/debug-iterator-support.md) estão habilitados. Essa macro substitui e combina a funcionalidade das macros antigas `_SECURE_SCL` e `_HAS_ITERATOR_DEBUGGING`.

## <a name="macro-values"></a>Valores da macro

A tabela a seguir resume os possíveis valores da macro `_ITERATOR_DEBUG_LEVEL`.

|Modo de compilação|Valor da macro|Descrição|
|----------------------|----------------|-----------------|
|**Depuração**|||
||0|Desabilita os iteradores verificados e desabilita a depuração do iterador.|
||1|Habilita os iteradores verificados e desabilita a depuração do iterador.|
||2 (padrão)|Habilita a depuração do iterador, iteradores verificados não são relevantes.|
|**Versão**|||
||0 (padrão)|Desabilita iteradores verificados.|
||1|Habilita iteradores verificados, a depuração do iterador não é revelante.|

No modo de versão, o compilador gera um erro se você especificar `_ITERATOR_DEBUG_LEVEL` como 2.

## <a name="remarks"></a>Comentários

A macro `_ITERATOR_DEBUG_LEVEL` controla se os [iteradores verificados](../standard-library/checked-iterators.md) estão habilitados e, no modo de Depuração, se o [suporte para depuração de iteradores](../standard-library/debug-iterator-support.md) está habilitado. Se `_ITERATOR_DEBUG_LEVEL` estiver definido como 1 ou 2, os iteradores verificados garantem que os limites de seu contêiner não serão substituídos. Se `_ITERATOR_DEBUG_LEVEL` for 0, os iteradores não serão verificados. Quando `_ITERATOR_DEBUG_LEVEL` é definido como 1, o uso de qualquer iterador não seguro gera um erro de tempo de execução e o programa é finalizado. Quando `_ITERATOR_DEBUG_LEVEL` é definido como 2, o iterador não seguro causa uma asserção e uma caixa de diálogo de erro de tempo de execução que permite interromper o depurador.

Como a macro `_ITERATOR_DEBUG_LEVEL` dá suporte a funcionalidades semelhantes das macros `_SECURE_SCL` e `_HAS_ITERATOR_DEBUGGING`, talvez você não saiba qual macro e valor de macro usar em uma determinada situação. Para evitar confusão, recomendamos que você use apenas a macro `_ITERATOR_DEBUG_LEVEL`. Esta tabela descreve o valor da macro `_ITERATOR_DEBUG_LEVEL` equivalente a ser usado para diversos valores de `_SECURE_SCL` e `_HAS_ITERATOR_DEBUGGING` no código existente.

|**_ITERATOR_DEBUG_LEVEL** |**_SECURE_SCL** |**_HAS_ITERATOR_DEBUGGING**|
|---|---|---|
|0 (padrão da versão)|0 (desabilitado)|0 (desabilitado)|
|1|1 (habilitado)|0 (desabilitado)|
|2 (padrão da depuração)|(não relevante)|1 (habilitado no modo de depuração)|

Para obter informações sobre como desabilitar avisos sobre iteradores verificados, consulte [_SCL_SECURE_NO_WARNINGS](../standard-library/scl-secure-no-warnings.md).

### <a name="example"></a>Exemplo

Para especificar um valor para a macro `_ITERATOR_DEBUG_LEVEL`, use uma opção do compilador [/D](../build/reference/d-preprocessor-definitions.md) para defini-lo na linha de comando ou use `#define` antes que os cabeçalhos da Biblioteca Padrão do C++ sejam incluídos nos arquivos de origem. Por exemplo, na linha de comando, para compilar *sample.cpp* no modo de depuração e usar o suporte para depuração de iteradores, você pode especificar a definição de macro `_ITERATOR_DEBUG_LEVEL`:

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
