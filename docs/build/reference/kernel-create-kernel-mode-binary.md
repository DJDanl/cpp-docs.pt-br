---
title: /kernel (criar binário do modo kernel)
description: A opção de/kernel do compilador do Microsoft C/C++ cria e vincula projetos para execução em modo kernel.
ms.date: 09/28/2020
f1_keywords:
- /kernel
- /kernel-
ms.assetid: 6d7fdff0-c3d1-4b78-9367-4da588ce8b05
ms.openlocfilehash: 8a8c02a6f102a52afbc52c154ce215ede3f38f74
ms.sourcegitcommit: a1676bf6caae05ecd698f26ed80c08828722b237
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/29/2020
ms.locfileid: "91509351"
---
# <a name="kernel-create-kernel-mode-binary"></a>/kernel (criar binário do modo kernel)

Cria um binário que pode ser executado no kernel do Windows. O código no projeto atual é compilado e vinculado usando um conjunto simplificado de recursos de linguagem C++ que são específicos do código executado no modo kernel.

## <a name="syntax"></a>Sintaxe

> **`/kernel`**

## <a name="remarks"></a>Comentários

A especificação da **`/kernel`** opção informa o compilador e o vinculador para arbitrar quais recursos de linguagem são permitidos no modo kernel e para garantir que você tenha capacidade expressiva suficiente para evitar a instabilidade em tempo de execução que seja exclusiva do modo kernel C++. Isso é feito por proibir o uso de recursos de linguagem C++ que causam interrupções no modo kernel. O compilador produz avisos para recursos de linguagem C++ que podem causar interrupções, mas não podem ser desabilitados.

A **`/kernel`** opção se aplica às fases do compilador e do vinculador de uma compilação e é definida no nível do projeto. Passe a **`/kernel`** opção para indicar ao compilador que o binário resultante, após a vinculação, deve ser carregado no kernel do Windows. O compilador restringirá o espectro de recursos de linguagem do C++ a um subconjunto compatível com o kernel.

A tabela a seguir lista as alterações no comportamento do compilador quando o **`/kernel`** é especificado.

| Tipo de comportamento | **`/kernel`** comportamento |
|--|--|
| Tratamento de exceções em C++ | Desabilitado. Todas as instâncias das **`throw`** **`try`** palavras-chave e emitem um erro do compilador (exceto para a especificação de exceção `throw()` ). Nenhuma **`/EH`** opção é compatível com **`/kernel`** , exceto para **`/EH-`** . |
| RTTI | Desabilitado. Todas as instâncias de **`dynamic_cast`** e **`typeid`** palavras-chave emitem um erro do compilador, a menos que **`dynamic_cast`** seja usado estaticamente. |
| `new` e `delete` | Você deve definir explicitamente o `new()` `delete()` operador OR. O compilador e o tempo de execução não fornecem uma definição padrão. |

As convenções de chamada personalizadas, a [`/GS`](gs-buffer-security-check.md) opção de compilação e todas as otimizações são permitidas quando você usa a **`/kernel`** opção. A inalinhamento é basicamente não afetada por **`/kernel`** , com a mesma semântica respeitada pelo compilador. Se você quiser certificar-se de que o **`__forceinline`** qualificador de inalinhamento seja respeitado, verifique se o aviso [C4714](../../error-messages/compiler-warnings/compiler-warning-level-4-c4714.md) está habilitado para que você saiba quando uma **`__forceinline`** função específica não está embutida.

Não há nenhum `#pragma` equivalente para controlar essa opção.

Quando o compilador passa o **`/kernel`** switch, ele predefine uma macro de pré-processador denominada `_KERNEL_MODE` e tem o valor **1**. Você pode usar essa macro para compilar o código condicionalmente com base em se o ambiente de execução está no modo de usuário ou no modo kernel. Por exemplo, o código a seguir especifica que a `MyNonPagedClass` classe deve estar em um segmento de memória não paginável quando é compilada para execução do modo kernel.

```cpp
#ifdef _KERNEL_MODE
#define NONPAGESECTION __declspec(code_seg("$kerneltext$"))
#else
#define NONPAGESECTION
#endif

class NONPAGESECTION MyNonPagedClass
{
   // ...
};
```

Algumas das seguintes combinações de arquitetura de destino e a **`/arch`** opção produzem um erro quando são usadas com **`/kernel`** :

- **`/arch:SSE`**, **`/arch:SSE2`** , **`/arch:AVX`** , **`/arch:AVX2`** e **`/arch:AVX512`** não têm suporte no x86. **`/arch:IA32`** Há suporte apenas para o **`/kernel`** no x86.

- **`/arch:AVX`**, **`/arch:AVX2`** e **`/arch:AVX512`** não são compatíveis com o **`/kernel`** no x64.

Criar com **`/kernel`** o também passa **`/kernel`** para o vinculador. Veja como a opção afeta o comportamento do vinculador:

- A vinculação incremental está desabilitada. Se você adicionar **`/incremental`** à linha de comando, o vinculador emitirá esse erro fatal:

   **erro fatal LNK1295: '/INCREMENTAL ' não compatível com a especificação '/KERNEL '; link sem '/INCREMENTAL '**

- O vinculador inspeciona cada arquivo de objeto (ou qualquer membro de arquivo incluído de bibliotecas estáticas) para ver se ele pode ter sido compilado usando a **`/kernel`** opção, mas não foi. Se alguma instância atender a esse critério, o vinculador ainda será vinculado com êxito, mas poderá emitir um aviso, conforme mostrado na tabela a seguir.

   | Comando | **`/kernel`** obj | obj não **`/kernel`** obj, MASM obj ou CVTRES | Combinação de **`/kernel`** e não **`/kernel`** objs tivessem |
   |--|--|--|--|
   | **`link /kernel`** | Sim | Sim | Sim com aviso LNK4257 |
   | **`link`** | Sim | Sim | Sim |

   **Objeto de vinculação de LNK4257 não compilado com/KERNEL; a imagem pode não ser executada**

A **`/kernel`** opção e a **`/driver`** opção funcionam de forma independente. Eles não têm nenhum efeito.

### <a name="to-set-the-kernel-compiler-option-in-visual-studio"></a>Para definir a opção de compilador/kernel no Visual Studio

1. Abra a caixa de diálogo **páginas de propriedades** do projeto. Para obter mais informações, confira [Definir as propriedades de build e do compilador do C++ no Visual Studio](../working-with-project-properties.md).

1. Selecione a **Configuration Properties**  >  página de propriedade de linha de comando**C/C++** Propriedades de configuração  >  **Command Line** .

1. Na caixa **Opções adicionais** , adicione *`/kernel`* . Escolha **OK** ou **aplicar** para salvar suas alterações.

## <a name="see-also"></a>Consulte também

[Opções do compilador MSVC](compiler-options.md)\
[Sintaxe de linha de comando do compilador MSVC](compiler-command-line-syntax.md)
