---
title: /GT (armazenamento local de thread seguro de fibra de suporte)
ms.date: 11/04/2016
f1_keywords:
- VC.Project.VCCLCompilerTool.EnableFiberSafeOptimizations
- /gt
helpviewer_keywords:
- /GT compiler option [C++]
- GT compiler option [C++]
- thread-local storage
- static thread-local storage and fiber safety
- -GT compiler option [C++]
- fiber-safe static thread-local storage compiler option [C++]
ms.assetid: 071fec79-c701-432b-9970-457344133159
ms.openlocfilehash: 417ac00a446f773a424553e42478a4f0cf58efc6
ms.sourcegitcommit: 8105b7003b89b73b4359644ff4281e1595352dda
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/14/2019
ms.locfileid: "57822507"
---
# <a name="gt-support-fiber-safe-thread-local-storage"></a>/GT (armazenamento local de thread seguro de fibra de suporte)

Dá suporte à segurança de fibra para dados alocados usando armazenamento de thread local estático, ou seja, os dados alocados com `__declspec(thread)`.

## <a name="syntax"></a>Sintaxe

```
/GT
```

## <a name="remarks"></a>Comentários

Dados declarados com `__declspec(thread)` é referenciado por meio de uma matriz de armazenamento local de thread (TLS). A matriz TLS é uma matriz de endereços que o sistema mantém para cada thread. Cada endereço nessa matriz fornece o local dos dados do armazenamento local de thread.

Uma fibra é um objeto leve que consiste em uma pilha e um contexto de registro e pode ser agendado em vários threads. Uma fibra pode executar em qualquer thread. Como uma fibra pode obter trocada e reiniciada posteriormente em um thread diferente, o endereço da matriz TLS não deve ser armazenado em cache ou otimizado como uma subexpressão comum em uma chamada de função (consulte a [/Og (otimizações globais)](og-global-optimizations.md) opção para detalhes). **/GT** impede essas otimizações.

### <a name="to-set-this-compiler-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do compilador no ambiente de desenvolvimento do Visual Studio

1. Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, consulte [propriedades de compilador e de build definida C++ no Visual Studio](../working-with-project-properties.md).

1. Clique o **C/C++** pasta.

1. Clique o **otimização** página de propriedades.

1. Modificar a **habilitar otimizações de fibra segura** propriedade.

### <a name="to-set-this-compiler-option-programmatically"></a>Para definir essa opção do compilador via programação

- Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCCLCompilerTool.EnableFiberSafeOptimizations%2A>.

## <a name="see-also"></a>Consulte também

[Opções do compilador MSVC](compiler-options.md)<br/>
[Sintaxe de linha de comando do compilador MSVC](compiler-command-line-syntax.md)
