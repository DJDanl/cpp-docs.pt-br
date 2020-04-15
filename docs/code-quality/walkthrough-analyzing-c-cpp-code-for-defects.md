---
title: 'Passo a passo: Analisando o código C/C++ para defeitos'
description: Demonstra como usar a análise de código com o Microsoft C++ no Visual Studio.
ms.date: 04/14/2020
ms.topic: conceptual
helpviewer_keywords:
- C/C++, code analysis
- code analysis, walkthroughs
- code, analyzing C/C++
- code analysis tool, walkthroughs
ms.openlocfilehash: fe9b3775199b2a18cf940b99e87852350f1fbea9
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81370210"
---
# <a name="walkthrough-analyzing-cc-code-for-defects"></a>Passo a passo: Analisando o código C/C++ para defeitos

Este passo a passo demonstra como analisar o código C/C++ para possíveis defeitos de código. Ele usa as ferramentas de análise de código para código C/C++.

Neste passo a passo, você vai:

- Executar análise de código em código nativo.
- Analise avisos de defeito de código.
- Trate o aviso como um erro.
- Anote o código fonte para melhorar a análise de defeitos de código.

## <a name="prerequisites"></a>Pré-requisitos

- Uma cópia da [amostra cppDemo](../code-quality/demo-sample.md).
- Compreensão básica de C/C++.

## <a name="run-code-analysis-on-native-code"></a>Executar análise de código em código nativo

### <a name="to-run-code-defect-analysis-on-native-code"></a>Para executar a análise de defeito de código em código nativo

::: moniker range=">=vs-2019"

1. Abra a solução CppDemo no Visual Studio.

     A solução CppDemo agora preenche **o Solution Explorer**.

1. No menu **Construir,** escolha **Reconstruir solução**.

     A solução é construída sem erros ou avisos.

1. No **Solution Explorer,** selecione o projeto CodeDefects.

1. No menu **Projeto,** escolha **Propriedades**.

     A caixa de diálogo **Páginas de propriedade CodeDefects** é exibida.

1. Selecione a página de propriedade Análise de **Código.**

1. Alterar a **análise de código de habilitação na** propriedade Build para **Sim**. Escolha **OK** para salvar suas alterações.

1. Reconstrua o projeto CodeDefects.

     Os avisos de análise de código são exibidos na janela **Lista de erros.**

::: moniker-end

::: moniker range="<=vs-2017"

1. Abra a solução CppDemo no Visual Studio.

     A solução CppDemo agora preenche **o Solution Explorer**.

1. No menu **Construir,** escolha **Reconstruir solução**.

     A solução é construída sem erros ou avisos.

     > [!NOTE]
     > No Visual Studio 2017, você pode ver `E1097 unknown attribute "no_init_all"` um aviso espúrio no motor IntelliSense. Ignore esse erro.

1. No **Solution Explorer,** selecione o projeto CodeDefects.

1. No menu **Projeto,** escolha **Propriedades**.

     A caixa de diálogo **Páginas de propriedade CodeDefects** é exibida.

1. Selecione a página de propriedade Análise de **Código.**

1. Selecione a **análise de código de habilitação na** caixa de seleção Build. Escolha **OK** para salvar suas alterações.

1. Reconstrua o projeto CodeDefects.

     Os avisos de análise de código são exibidos na janela **Lista de erros.**

::: moniker-end

### <a name="to-analyze-code-defect-warnings"></a>Para analisar avisos de defeito de código

1. No menu **Exibir,** escolha **Lista de erros**.

     Este item do menu pode não estar visível. Depende do perfil do desenvolvedor que você escolheu no Visual Studio. Você pode ter que apontar para **outros Windows** no menu **Exibir** e, em seguida, escolher Lista **de erros**.

1. Na janela **Lista de erros,** clique duas vezes no seguinte aviso:

     C6230: Elenco implícito entre tipos semanticamente diferentes: usando HRESULT em um contexto booleano.

     O editor de código exibe a linha `bool ProcessDomain()`que causou o aviso dentro da função . Este aviso indica `HRESULT` que a está sendo usada em uma declaração "se" onde um resultado booleano é esperado. É tipicamente um erro, porque `S_OK` quando o HRESULT é devolvido de uma função indica sucesso, mas `false`quando convertido em um valor booleano ele avalia para .

1. Corrija este aviso `SUCCEEDED` usando a macro, que se converte para `true` quando um `HRESULT` valor de retorno indicar sucesso. Seu código deve se assemelhar ao seguinte código:

   ```cpp
   if (SUCCEEDED(ReadUserAccount()))
   ```

1. Na **lista de erros,** clique duas vezes no seguinte aviso:

     C6282: Operador incorreto: atribuição de constante no contexto booleano. Considere usar '==' em vez disso.

1. Corrija este aviso testando a igualdade. Seu código deve ser semelhante ao seguinte código:

   ```cpp
   if ((len == ACCOUNT_DOMAIN_LEN) || (g_userAccount[len] != L'\\'))
   ```

1. Corrija os avisos C6001 restantes `i` na `j` Lista **de Erros** inicializando e em 0.

1. Reconstrua o projeto CodeDefects.

     O projeto é construído sem avisos ou erros.

## <a name="correct-source-code-annotation-warnings"></a>Avisos corretos de anotação de código fonte

### <a name="to-enable-the-source-code-annotation-warnings-in-annotationc"></a>Para habilitar os avisos de anotação de código fonte em anotação.c

::: moniker range=">=vs-2019"

1. No Solution Explorer, selecione o projeto Anotações.

1. No menu **Projeto,** escolha **Propriedades**.

     A caixa de diálogo **Páginas de Propriedades de Anotações** é exibida.

1. Selecione a página de propriedade Análise de **Código.**

1. Alterar a **análise de código de habilitação na** propriedade Build para **Sim**. Escolha **OK** para salvar suas alterações.

::: moniker-end

::: moniker range="<=vs-2017"

1. No Solution Explorer, selecione o projeto Anotações.

1. No menu **Projeto,** escolha **Propriedades**.

     A caixa de diálogo **Páginas de Propriedades de Anotações** é exibida.

1. Selecione a página de propriedade Análise de **Código.**

1. Selecione a **análise de código de habilitação na** caixa de seleção Build. Escolha **OK** para salvar suas alterações.

::: moniker-end

### <a name="to-correct-the-source-code-annotation-warnings-in-annotationc"></a>Para corrigir os avisos de anotação do código fonte em anotação.c

1. Reconstrua o projeto Anotações.

1. No **menu Build,** escolha **Executar análise de código em anotações**.

1. Na **lista de erros,** clique duas vezes no seguinte aviso:

     C6011: Dereferencing NULL pointer 'newNode'.

     Este aviso indica falha do chamador para verificar o valor de retorno. Neste caso, uma `AllocateNode` chamada pode retornar um valor NULL. Consulte o arquivo de cabeçalho anotações.h para a declaração de função para `AllocateNode`.

1. O cursor está no local no arquivo anotações.cpp onde ocorreu o aviso.

1. Para corrigir este aviso, use uma declaração 'if' para testar o valor de retorno. Seu código deve se assemelhar ao seguinte código:

   ```cpp
   LinkedList* newNode = AllocateNode();
   if (nullptr != newNode)
   {
       newNode->data = value;
       newNode->next = 0;
       node->next = newNode;
   }
   ```

1. Reconstrua o projeto Anotações.

     O projeto é construído sem avisos ou erros.

## <a name="use-source-code-annotation-to-discover-more-issues"></a>Use anotação de código-fonte para descobrir mais problemas

### <a name="to-use-source-code-annotation"></a>Para usar a notação de código fonte

1. Anotar parâmetros formais e o `AddTail` valor de retorno da função para indicar que os valores do ponteiro podem ser nulos:

   ```cpp
   _Ret_maybenull_ LinkedList* AddTail(_Maybenull_ LinkedList* node, int value)
   ```

1. No menu **Compilar**, escolha **Executar Análise de Código na Solução**.

1. Na **lista de erros,** clique duas vezes no seguinte aviso:

     C6011: Dereferencing NULL pointer 'node'.

     Este aviso indica que o nó passado na função pode ser nulo.

1. Para corrigir este aviso, use uma declaração 'if' no início da função para testar o valor passado. Seu código deve se assemelhar ao seguinte código:

   ```cpp
   if (nullptr == node)
   {
        return nullptr;
   }
   ```

1. No menu **Compilar**, escolha **Executar Análise de Código na Solução**.

     O projeto agora é construído sem avisos ou erros.

## <a name="see-also"></a>Confira também

[Passo a passo: Analisando código gerenciado para defeitos de código](/visualstudio/code-quality/walkthrough-analyzing-managed-code-for-code-defects)\
[Análise de código para C/C++](../code-quality/code-analysis-for-c-cpp-overview.md)
