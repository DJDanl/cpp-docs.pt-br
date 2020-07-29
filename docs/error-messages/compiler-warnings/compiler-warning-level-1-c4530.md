---
title: Aviso do compilador (nível 1) C4530
description: Guia de referência para o C4530 de aviso do compilador do Microsoft C++.
ms.date: 04/02/2020
f1_keywords:
- C4530
helpviewer_keywords:
- C4530
ms.assetid: a04dcdb2-84db-459d-9e5e-4e743887465f
ms.openlocfilehash: fe0a2b4c8eb881327f3e59d66e7e6941f0a2cad8
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87230656"
---
# <a name="compiler-warning-level-1-c4530"></a>Aviso do compilador (nível 1) C4530

> Manipulador de exceção C++ usado, mas semântica de liberação não está habilitada. Especificar/EHsc

O código usa a manipulação de exceção do C++, mas [/EHsc](../../build/reference/eh-exception-handling-model.md) não foi incluído nas opções do compilador.

## <a name="remarks"></a>Comentários

O compilador requer a **`/EHsc`** opção de criar código c++ que segue o padrão c++ para manipulação de exceção. A *semântica de desenrolamento* C++ padrão especifica que objetos e quadros de pilha construídos entre onde uma exceção é lançada e onde ele é capturado devem ser destruídos e seus recursos recuperados. Esse processo é conhecido como *desenrolar a pilha*.

A **`/EHsc`** opção informa o compilador para gerar código que chama os destruidores em objetos de armazenamento automático quando uma exceção passa pelo quadro de pilha que o contém. Os objetos de *armazenamento automático* são objetos alocados na pilha, como variáveis locais. Ele é chamado de armazenamento automático porque é alocado automaticamente quando as funções são chamadas e liberado automaticamente quando retornam. Um registro de *ativação* é os dados colocados na pilha quando uma função é chamada, juntamente com seu armazenamento automático.

Quando uma exceção é lançada, ela pode percorrer várias molduras de pilha antes de ser detectada. Esses quadros de pilha devem ser rebobinados à medida que a exceção passa por eles na ordem de chamada inversa. Os objetos de armazenamento automático em cada registro de ativação devem ser destruídos para recuperar seus recursos corretamente. É o mesmo processo de destruição e recuperação que ocorre automaticamente quando uma função retorna normalmente.

Quando a **`/EHsc`** opção não está habilitada, os objetos de armazenamento automático nos quadros de pilha entre a função de lançamento e a função em que a exceção é capturada não são destruídos. Somente os objetos de armazenamento automático criados em **`try`** um **`catch`** bloco ou são destruídos, o que pode levar a vazamentos de recursos significativos e a outro comportamento inesperado.

Se nenhuma exceção puder ser lançada em seu executável, você poderá ignorar esse aviso com segurança. Alguns códigos podem exigir outras opções de tratamento de exceção. Para obter mais informações, consulte [/eh](../../build/reference/eh-exception-handling-model.md).

## <a name="example"></a>Exemplo

O exemplo a seguir gera C4530:

```cpp
// C4530.cpp
// compile with: /W1
int main() {
   try{} catch(int*) {}   // C4530
}
```

Compile o exemplo com **`/EHsc`** para resolver o aviso.
