---
title: 'Walkthrough: analisando o código C/C++ para defeitos'
description: Demonstra como usar a análise de código com o Microsoft C++ no Visual Studio.
ms.date: 04/14/2020
ms.topic: conceptual
helpviewer_keywords:
- C/C++, code analysis
- code analysis, walkthroughs
- code, analyzing C/C++
- code analysis tool, walkthroughs
ms.openlocfilehash: 65da18f5f6d1972276f1cb8e306e82314282e40a
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87227706"
---
# <a name="walkthrough-analyzing-cc-code-for-defects"></a>Walkthrough: analisando o código C/C++ para defeitos

Este tutorial demonstra como analisar o código C/C++ para possíveis defeitos de código. Ele usa as ferramentas de análise de código para código C/C++.

Neste tutorial, você vai:

- Execute a análise de código no código nativo.
- Analise os avisos de defeito de código.
- Trate o aviso como um erro.
- Anote o código-fonte para melhorar a análise de defeitos de código.

## <a name="prerequisites"></a>Pré-requisitos

- Uma cópia do [exemplo de CppDemo](../code-quality/demo-sample.md).
- Noções básicas sobre C/C++.

## <a name="run-code-analysis-on-native-code"></a>Executar análise de código em código nativo

### <a name="to-run-code-defect-analysis-on-native-code"></a>Para executar a análise de defeitos de código em código nativo

::: moniker range=">=vs-2019"

1. Abra a solução CppDemo no Visual Studio.

     A solução CppDemo agora preenche **Gerenciador de soluções**.

1. No menu **Compilar** , escolha **Recompilar solução**.

     A solução é compilada sem erros ou avisos.

1. Em **Gerenciador de soluções**, selecione o projeto CodeDefects.

1. No menu **projeto** , escolha **Propriedades**.

     A caixa de diálogo **páginas de propriedades do CodeDefects** é exibida.

1. Selecione a página de propriedades de **análise de código** .

1. Altere a propriedade **Habilitar análise de código na compilação** para **Sim**. Escolha **OK** para salvar suas alterações.

1. Reconstrua o projeto CodeDefects.

     Os avisos de análise de código são exibidos na janela **lista de erros** .

::: moniker-end

::: moniker range="<=vs-2017"

1. Abra a solução CppDemo no Visual Studio.

     A solução CppDemo agora preenche **Gerenciador de soluções**.

1. No menu **Compilar** , escolha **Recompilar solução**.

     A solução é compilada sem erros ou avisos.

     > [!NOTE]
     > No Visual Studio 2017, você pode ver um aviso falso `E1097 unknown attribute "no_init_all"` no mecanismo do IntelliSense. Ignore esse erro.

1. Em **Gerenciador de soluções**, selecione o projeto CodeDefects.

1. No menu **projeto** , escolha **Propriedades**.

     A caixa de diálogo **páginas de propriedades do CodeDefects** é exibida.

1. Selecione a página de propriedades de **análise de código** .

1. Marque a caixa de seleção **Habilitar análise de código na compilação** . Escolha **OK** para salvar suas alterações.

1. Reconstrua o projeto CodeDefects.

     Os avisos de análise de código são exibidos na janela **lista de erros** .

::: moniker-end

### <a name="to-analyze-code-defect-warnings"></a>Para analisar avisos de defeito de código

1. No menu **Exibir** , escolha **lista de erros**.

     Este item de menu pode não estar visível. Depende do perfil de desenvolvedor que você escolheu no Visual Studio. Talvez você precise apontar para **outras janelas** no menu **Exibir** e, em seguida, escolher **lista de erros**.

1. Na janela **lista de erros** , clique duas vezes no seguinte aviso:

     C6230: conversão implícita entre tipos semanticamente diferentes: usando HRESULT em um contexto booliano.

     O editor de código exibe a linha que causou o aviso dentro da função `bool ProcessDomain()` . Esse aviso indica que um `HRESULT` está sendo usado em uma instrução ' If ' onde um resultado booliano é esperado. Normalmente, é um erro, porque quando o `S_OK` HRESULT é retornado de uma função, ele indica êxito, mas quando convertido em um valor booliano, ele é avaliado como **`false`** .

1. Corrija esse aviso usando a `SUCCEEDED` macro, que é convertida em **`true`** quando um `HRESULT` valor de retorno indica êxito. Seu código deve ser semelhante ao seguinte código:

   ```cpp
   if (SUCCEEDED(ReadUserAccount()))
   ```

1. No **lista de erros**, clique duas vezes no seguinte aviso:

     C6282: operador incorreto: atribuição de constante no contexto booliano. Considere usar ' = = ' em vez disso.

1. Corrija esse aviso testando a igualdade. Seu código deve ser semelhante ao seguinte código:

   ```cpp
   if ((len == ACCOUNT_DOMAIN_LEN) || (g_userAccount[len] != L'\\'))
   ```

1. Corrija os avisos C6001 restantes na **lista de erros** inicializando `i` e `j` como 0.

1. Reconstrua o projeto CodeDefects.

     O projeto é compilado sem avisos ou erros.

## <a name="correct-source-code-annotation-warnings"></a>Avisos de anotação de código-fonte corretos

### <a name="to-enable-the-source-code-annotation-warnings-in-annotationc"></a>Para habilitar os avisos de anotação de código-fonte em Annotation. c

::: moniker range=">=vs-2019"

1. Em Gerenciador de Soluções, selecione o projeto anotações.

1. No menu **projeto** , escolha **Propriedades**.

     A caixa de diálogo **páginas de propriedades de anotações** é exibida.

1. Selecione a página de propriedades de **análise de código** .

1. Altere a propriedade **Habilitar análise de código na compilação** para **Sim**. Escolha **OK** para salvar suas alterações.

::: moniker-end

::: moniker range="<=vs-2017"

1. Em Gerenciador de Soluções, selecione o projeto anotações.

1. No menu **projeto** , escolha **Propriedades**.

     A caixa de diálogo **páginas de propriedades de anotações** é exibida.

1. Selecione a página de propriedades de **análise de código** .

1. Marque a caixa de seleção **Habilitar análise de código na compilação** . Escolha **OK** para salvar suas alterações.

::: moniker-end

### <a name="to-correct-the-source-code-annotation-warnings-in-annotationc"></a>Para corrigir os avisos de anotação de código-fonte em Annotation. c

1. Recrie o projeto de anotações.

1. No menu **Compilar** , escolha **executar análise de código em anotações**.

1. No **lista de erros**, clique duas vezes no seguinte aviso:

     C6011: desreferenciando o ponteiro nulo ' newNode '.

     Esse aviso indica falha pelo chamador para verificar o valor de retorno. Nesse caso, uma chamada para `AllocateNode` pode retornar um valor nulo. Consulte o arquivo de cabeçalho annotations. h para a declaração de função para `AllocateNode` .

1. O cursor está no local no arquivo annotations. cpp em que o aviso ocorreu.

1. Para corrigir esse aviso, use uma instrução ' If ' para testar o valor de retorno. Seu código deve ser semelhante ao seguinte código:

   ```cpp
   LinkedList* newNode = AllocateNode();
   if (nullptr != newNode)
   {
       newNode->data = value;
       newNode->next = 0;
       node->next = newNode;
   }
   ```

1. Recrie o projeto de anotações.

     O projeto é compilado sem avisos ou erros.

## <a name="use-source-code-annotation-to-discover-more-issues"></a>Use a anotação de código-fonte para descobrir mais problemas

### <a name="to-use-source-code-annotation"></a>Para usar a anotação de código-fonte

1. Anote os parâmetros formais e o valor de retorno da função `AddTail` para indicar que os valores de ponteiro podem ser nulos:

   ```cpp
   _Ret_maybenull_ LinkedList* AddTail(_Maybenull_ LinkedList* node, int value)
   ```

1. No menu **Compilar**, escolha **Executar Análise de Código na Solução**.

1. No **lista de erros**, clique duas vezes no seguinte aviso:

     C6011: desreferenciando o ponteiro nulo ' node '.

     Esse aviso indica que o nó passado para a função pode ser nulo.

1. Para corrigir esse aviso, use uma instrução ' If ' no início da função para testar o valor passado. Seu código deve ser semelhante ao seguinte código:

   ```cpp
   if (nullptr == node)
   {
        return nullptr;
   }
   ```

1. No menu **Compilar**, escolha **Executar Análise de Código na Solução**.

     Agora, o projeto é compilado sem avisos ou erros.

## <a name="see-also"></a>Confira também

[Walkthrough: analisando código gerenciado para defeitos de código](/visualstudio/code-quality/walkthrough-analyzing-managed-code-for-code-defects)\
[Análise de código para C/C++](../code-quality/code-analysis-for-c-cpp-overview.md)
