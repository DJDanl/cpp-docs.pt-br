---
title: Aviso do compilador (nível 1) C4530
description: Guia de referência para aviso c++ do compilador Microsoft C++.
ms.date: 04/02/2020
f1_keywords:
- C4530
helpviewer_keywords:
- C4530
ms.assetid: a04dcdb2-84db-459d-9e5e-4e743887465f
ms.openlocfilehash: 9de88a4b0b6c7176ff82b68c92d09d9fe75a70b2
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81369777"
---
# <a name="compiler-warning-level-1-c4530"></a>Aviso do compilador (nível 1) C4530

> O manipulador de exceção C++ usado, mas a semântica de sumidência não está ativada. Especificar /EHsc

O código usa o manuseio de exceção C++, mas [/EHsc](../../build/reference/eh-exception-handling-model.md) não foi incluído nas opções do compilador.

## <a name="remarks"></a>Comentários

O compilador requer **`/EHsc`** a opção de criar o código C++ que segue o padrão C++ para o manuseio de exceções. A *semântica padrão* C++ descontrai a semântica especifica que objetos e quadros de pilha construídos entre onde uma exceção é lançada e onde é capturado devem ser destruídos e seus recursos recuperados. Este processo é conhecido como *desenrolar a pilha*.

A **`/EHsc`** opção diz ao compilador para gerar código que chama os destruidores em objetos de armazenamento automáticoquando uma exceção passa pelo quadro de pilha contendo. *Objetos de armazenamento automáticos* são objetos alocados na pilha, como variáveis locais. É chamado de armazenamento automático porque é alocado automaticamente quando as funções são chamadas, e liberado automaticamente quando eles retornam. Um *quadro de pilha* é os dados colocados na pilha quando uma função é chamada, juntamente com seu armazenamento automático.

Quando uma exceção é lançada, ela pode viajar através de vários quadros de pilha antes de ser capturada. Esses quadros de pilha devem ser desenrolados à medida que a exceção passa por eles em ordem de chamada inversa. Os objetos de armazenamento automático sumidem em cada quadro de pilha para recuperar seus recursos de forma limpa. É o mesmo processo de destruição e recuperação que acontece automaticamente quando uma função retorna normalmente.

Quando **`/EHsc`** a opção não está ativada, objetos de armazenamento automáticos nos quadros de pilha entre a função de arremesso e a função onde a exceção é capturada não são destruídos. Apenas os objetos de armazenamento automáticocriados em um bloco **de tentativa** ou **captura** são destruídos, o que pode levar a vazamentos significativos de recursos e outros comportamentos inesperados.

Se nenhuma exceção puder ser lançada em seu executável, você pode ignorar este aviso com segurança. Alguns códigos podem exigir outras opções de manipulação de exceção. Para obter mais informações, consulte [/EH](../../build/reference/eh-exception-handling-model.md).

## <a name="example"></a>Exemplo

A seguinte amostra gera C4530:

```cpp
// C4530.cpp
// compile with: /W1
int main() {
   try{} catch(int*) {}   // C4530
}
```

Compilar a **`/EHsc`** amostra com a resolução do aviso.
