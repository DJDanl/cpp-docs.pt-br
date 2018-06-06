---
title: 'Como: migrar para o clr-: safe (C + + CLI) | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-cli
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- migration [C++], verifiable assemblies
- upgrading Visual C++ applications, verifiable assemblies
- verifiable assemblies [C++], migrating to
- /clr compiler option [C++], migrating to /clr:safe
ms.assetid: 75f9aae9-1dcc-448a-aa11-2d96f972f9d2
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- dotnet
ms.openlocfilehash: d72be19eb893a74a17a988e8c14c6bdaba766cbc
ms.sourcegitcommit: a4454b91d556a3dc43d8755cdcdeabcc9285a20e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/04/2018
ms.locfileid: "34704508"
---
# <a name="how-to-migrate-to-clrsafe-ccli"></a>Como migrar para /clr:safe (C++/CLI)

> [!IMPORTANT]
> O **/clr: pure** e **/CLR: safe** opções do compilador são substituídas no Visual Studio 2015 e sem suporte no Visual Studio de 2017. Se você precisar de seguros assemblies do CLR, é recomendável que porta seu código c#.

Se você estiver usando uma versão anterior do conjunto de ferramentas do compilador Visual C++ de antes de 2017 do Visual Studio, você pode gerar verificáveis componentes usando **/CLR: safe**, que faz com que o compilador gere erros para cada não verificável construção de código.

## <a name="remarks"></a>Comentários

Os problemas a seguir geram erros de capacidade de verificação:

- Tipos nativos. Mesmo se não for usado, a declaração de classes nativas, estruturas, ponteiros ou matrizes impedirá a compilação.

- Variáveis globais

- Chamadas de função em qualquer biblioteca não gerenciada, incluindo chamadas de função de tempo de execução de linguagem comum

- Uma função verificável não pode conter um [operador static_cast](../cpp/static-cast-operator.md) para conversão inferior. O [operador static_cast](../cpp/static-cast-operator.md) pode ser usado para conversão entre tipos primitivos, mas para conversão de baixo [safe_cast](../windows/safe-cast-cpp-component-extensions.md) ou uma conversão C-Style (que é implementado como um [safe_cast](../windows/safe-cast-cpp-component-extensions.md)) deve ser usado.

- Uma função verificável não pode conter um [operador reinterpret_cast](../cpp/reinterpret-cast-operator.md) (ou equivalente qualquer conversão C-style).

- Uma função verificável não pode executar cálculos aritméticos em uma [interior_ptr (C + + CLI)](../windows/interior-ptr-cpp-cli.md). Ele só pode atribuir a ela e referência.

- Uma função verificável somente pode lançar ou capturar ponteiros para tipos de referência, para que tipos de valor devem ser boxed antes de lançar.

- Uma função verificável somente é possível chamar funções verificáveis (que não são permitidas chamadas para o common language runtime, incluir `AtEntry` / `AtExit`, e, portanto, global construtores não são permitidos).

- Não é possível usar uma classe verificável <xref:System.Runtime.InteropServices.LayoutKind>.

- Se criar um EXE, uma função principal não pode declarar qualquer parâmetro, portanto <xref:System.Environment.GetCommandLineArgs%2A> deve ser usada para recuperar os argumentos de linha de comando.

- Fazendo uma chamada de máquina virtual para uma função virtual. Por exemplo:

   ```cpp
   // not_verifiable.cpp
   // compile with: /clr
   ref struct A {
      virtual void Test() {}
   };

   ref struct B : A {};

   int main() {
      B^ b1 = gcnew B;
      b1->A::Test();   // Non-virtual call to virtual function
   }
   ```

Além disso, as seguintes palavras-chave não podem ser usadas no código verificável:

- [não gerenciado](../preprocessor/managed-unmanaged.md) e [pacote](../preprocessor/pack.md) pragmas

- [naked](../cpp/naked-cpp.md) e [alinhar](../cpp/align-cpp.md) [declspec](../cpp/declspec.md) modificadores

- [__asm](../assembler/inline/asm.md)

- [__based](../cpp/based-grammar.md)

- [Try](../cpp/try-except-statement.md) e `__except`

## <a name="see-also"></a>Consulte também

- [Código puro e verificável (C++/CLI)](../dotnet/pure-and-verifiable-code-cpp-cli.md)
