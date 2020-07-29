---
title: /kernel (criar binário do modo kernel)
ms.date: 11/04/2016
f1_keywords:
- /kernel
- /kernel-
ms.assetid: 6d7fdff0-c3d1-4b78-9367-4da588ce8b05
ms.openlocfilehash: bcef52144e4da932e9e1b6acbcd5f2170c4c7f86
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87211938"
---
# <a name="kernel-create-kernel-mode-binary"></a>/kernel (criar binário do modo kernel)

Cria um binário que pode ser executado no kernel do Windows.

## <a name="syntax"></a>Sintaxe

```
/kernel[-]
```

## <a name="arguments"></a>Argumentos

**/kernel**<br/>
O código no projeto atual é compilado e vinculado usando um conjunto de regras de linguagem do C++ que são específicas do código que será executado no modo kernel.

**/kernel**<br/>
O código no projeto atual é compilado e vinculado sem usar as regras de linguagem do C++ que são específicas para o código que será executado no modo kernel.

## <a name="remarks"></a>Comentários

Não há nenhum `#pragma` equivalente para controlar essa opção.

A especificação da opção **/kernel** informa o compilador e o vinculador para arbitrar quais recursos de linguagem são permitidos no modo kernel e para garantir que você tenha capacidade expressiva suficiente para evitar a instabilidade em tempo de execução que seja exclusiva do modo kernel C++. Isso é feito por proibir o uso de recursos de linguagem C++ que causam interrupções no modo kernel e fornecendo avisos para recursos de linguagem do C++ que podem causar interrupção, mas não pode ser desabilitado.

A opção **/kernel** se aplica às fases do compilador e do vinculador de uma compilação e é definida no nível do projeto. Passe a opção **/kernel** para indicar ao compilador que o binário resultante, após a vinculação, deve ser carregado no kernel do Windows. O compilador restringirá o espectro de recursos de linguagem do C++ a um subconjunto compatível com o kernel.

A tabela a seguir lista as alterações no comportamento do compilador quando **/kernel** é especificado.

|Tipo de comportamento|**/kernel** Comportamento|
|-------------------|---------------------------|
|Tratamento de exceções C++|Desabilitado. Todas as instâncias das **`throw`** **`try`** palavras-chave e emitem um erro do compilador (exceto para a especificação de exceção `throw()` ). Nenhuma opção de **/eh** é compatível com **/kernel**, exceto para **/eh-**.|
|RTTI|Desabilitado. Todas as instâncias de **`dynamic_cast`** e **`typeid`** palavras-chave emitem um erro do compilador, a menos que **`dynamic_cast`** seja usado estaticamente.|
|`new` e `delete`|Você deve definir explicitamente o `new()` `delete()` operador OR; nem o compilador nem o tempo de execução fornecerão uma definição padrão.|

As convenções de chamada personalizadas, a opção de compilação [/GS](gs-buffer-security-check.md) e todas as otimizações são permitidas quando você usa a opção **/kernel** . A inalinhamento é basicamente não afetada por **/kernel**, com a mesma semântica respeitada pelo compilador. Se você quiser certificar-se de que o **`__forceinline`** qualificador de inalinhamento seja respeitado, verifique se o aviso [C4714](../../error-messages/compiler-warnings/compiler-warning-level-4-c4714.md) está habilitado para que você saiba quando uma **`__forceinline`** função específica não está embutida.

Quando o compilador passa a opção **/kernel** , ele predefine uma macro de pré-processador denominada `_KERNEL_MODE` e tem o valor **1**. Você pode usar isso para compilar código condicionalmente com base em se o ambiente de execução está no modo de usuário ou no modo kernel. Por exemplo, o código a seguir especifica que a classe deve estar em um segmento de memória não paginável quando é compilada para execução do modo kernel.

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

Algumas das seguintes combinações de arquitetura de destino e a opção **/Arch** produzem um erro quando são usadas com **/kernel**:

- **/Arch: {SSE&#124;SSE2&#124;AVX}** não tem suporte no x86. Somente **/Arch: IA32** tem suporte com **/kernel** em x86.

- **/Arch:** não há suporte para AVX com **/kernel** em x64.

Criar com **/kernel** também passa o **/kernel** para o vinculador. É assim que isso afeta o comportamento do vinculador:

- A vinculação incremental está desabilitada. Se você adicionar **/incremental** à linha de comando, o vinculador emitirá esse erro fatal:

   **LINK: erro fatal LNK1295: '/INCREMENTAL ' não compatível com a especificação '/KERNEL '; link sem '/INCREMENTAL '**

- O vinculador inspeciona cada arquivo de objeto (ou qualquer membro de arquivo incluído de bibliotecas estáticas) para ver se ele pode ter sido compilado usando a opção **/kernel** , mas não foi. Se alguma instância atender a esse critério, o vinculador ainda será vinculado com êxito, mas poderá emitir um aviso, conforme mostrado na tabela a seguir.

   ||**/kernel** obj|**/kernel-** obj, MASM obj ou cvtresed|Combinação de **/kernel** e **/kernel-** objs tivessem|
   |-|----------------------|-----------------------------------------------|-------------------------------------------------|
   |**vincular/kernel**|Sim|Sim|Sim com aviso LNK4257|
   |**criar**|Sim|Sim|Sim|

   **Objeto de vinculação de LNK4257 não compilado com/KERNEL; a imagem pode não ser executada**

A opção **/kernel** e a opção **/Driver** operam de forma independente e nenhuma afeta a outra.

### <a name="to-set-the-kernel-compiler-option-in-visual-studio"></a>Para definir a opção de compilador/kernel no Visual Studio

1. Abra a caixa de diálogo **páginas de propriedades** do projeto. Para obter mais informações, confira [Definir as propriedades de build e do compilador do C++ no Visual Studio](../working-with-project-properties.md).

1. Selecione a pasta **C/C++** .

1. Selecione a página de propriedades de **linha de comando** .

1. Na caixa **Opções adicionais** , adicione `/kernel` ou `/kernel-` .

## <a name="see-also"></a>Confira também

[Opções do compilador MSVC](compiler-options.md)<br/>
[Sintaxe de linha de comando do compilador MSVC](compiler-command-line-syntax.md)
