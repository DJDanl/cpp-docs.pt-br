---
title: /GT (armazenamento local de thread seguro de fibra de suporte)
description: A opção de compilador MSVC/GT permite otimizações seguras para dados de armazenamento local de thread.
ms.date: 07/08/2020
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
ms.openlocfilehash: 1b1d9f6514cec8c3d247f86be063f2ac3e0dfe72
ms.sourcegitcommit: 80c8a512b361bd84e38958beb1a1bf6db7434021
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/09/2020
ms.locfileid: "86180806"
---
# <a name="gt-support-fiber-safe-thread-local-storage"></a>`/GT`(Suporte ao armazenamento local de thread de fibra segura)

Dá suporte à segurança de fibra para dados alocados usando o armazenamento local de thread estático, ou seja, os dados alocados com o `__declspec(thread)` .

## <a name="syntax"></a>Sintaxe

> **`/GT`**

## <a name="remarks"></a>Comentários

Os dados declarados com `__declspec(thread)` são referenciados por meio de uma matriz de armazenamento local de thread (TLS). A matriz TLS é uma matriz de endereços que o sistema mantém para cada thread. Cada endereço nessa matriz fornece o local dos dados de armazenamento local de thread.

Uma fibra é um objeto leve que consiste em uma pilha e um contexto de registro e pode ser agendado em vários threads. Uma fibra pode ser executada em qualquer thread. Como uma fibra pode ser trocada e reiniciada posteriormente em um thread diferente, o compilador não deve o cache do endereço da matriz TLS ou o otimiza como uma subexpressão comum em uma chamada de função. **`/GT`** impede essas otimizações.

### <a name="to-set-this-compiler-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do compilador no ambiente de desenvolvimento do Visual Studio

1. Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, confira [Definir as propriedades de build e do compilador do C++ no Visual Studio](../working-with-project-properties.md).

1. Selecione a página de propriedades de otimização de **configuração**de  >  **C/C++**  >  **Optimization** .

1. Modifique a propriedade **habilitar otimizações de fibra segura** .

### <a name="to-set-this-compiler-option-programmatically"></a>Para definir essa opção do compilador via programação

- Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCCLCompilerTool.EnableFiberSafeOptimizations%2A>.

## <a name="see-also"></a>Veja também

[Opções do compilador MSVC](compiler-options.md)<br/>
[Sintaxe da linha de comando do compilador MSVC](compiler-command-line-syntax.md)
