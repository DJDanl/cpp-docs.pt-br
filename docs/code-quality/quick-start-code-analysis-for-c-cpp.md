---
title: 'Início Rápido: análise de código para C/C++'
description: Execute a análise estática C++ no código do Visual Studio para detectar problemas comuns de codificação e defeitos.
ms.date: 11/04/2016
ms.topic: conceptual
helpviewer_keywords:
- C/C++ code analysis
- code analysis,C/C++
ms.openlocfilehash: 5ee8f702ddf489732f664ae73eed75b18dc46e86
ms.sourcegitcommit: 7bea0420d0e476287641edeb33a9d5689a98cb98
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/17/2020
ms.locfileid: "77418777"
---
# <a name="quickstart-code-analysis-for-cc"></a>Início Rápido: análise de código para C/C++

Você pode melhorar a qualidade do seu aplicativo executando a análise de código regularmente em C C++ ou Code. Isso pode ajudá-lo a encontrar problemas comuns, violações de boa prática de programação ou defeitos que são difíceis de descobrir por meio de testes. Os avisos da análise de código diferem dos erros e avisos do compilador porque a análise de código procura por padrões de código específicos que são válidos, mas que ainda podem criar problemas para você ou outras pessoas que usam seu código.

## <a name="configure-rule-sets-for-a-project"></a>Configurar conjuntos de regras para um projeto

1. Em **Gerenciador de soluções**, abra o menu de atalho para o nome do projeto e escolha **Propriedades**.

1. Opcionalmente, nas listas de **configuração** e **plataforma** , escolha a configuração de compilação e a plataforma de destino.

1. Para executar a análise de código toda vez que o projeto for criado usando a configuração selecionada, marque a caixa de seleção **Habilitar análise de código na compilação** . Você também pode executar a análise de código manualmente abrindo o menu **analisar** e, em seguida, escolhendo **executar análise de código no** *ProjectName* ou **executar análise de código no arquivo**.

1. Escolha o [conjunto de regras](using-rule-sets-to-specify-the-cpp-rules-to-run.md) que você deseja usar ou crie um [conjunto de regras personalizado](using-rule-sets-to-specify-the-cpp-rules-to-run.md#to-create-a-rule-set-in-a-text-editor). Se estiver usando LLVM/Clang-CL, consulte [usando Clang-organizar no Visual Studio](../code-quality/clang-tidy.md) para configurar as opções de análise de Clang.

### <a name="standard-cc-rule-sets"></a>Conjuntos de regrasC++ /C padrão

O Visual Studio inclui dois conjuntos padrão de regras para código nativo:

|Conjunto de regras|DESCRIÇÃO|
|--------------|-----------------|
|Regras recomendadas mínimas do Microsoft Native|Esse conjunto de regras enfoca os problemas mais críticos em seu código nativo, incluindo falhas potenciais de segurança e falhas do aplicativo. Você deve incluir esse conjunto de regras em qualquer conjunto personalizado de regras que você criar para seus projetos nativos.|
|Regras nativas recomendadas da Microsoft|Esse conjunto de regras aborda uma ampla gama de problemas. Ele inclui todas as regras nas regras recomendadas do mínimo nativo da Microsoft.|

## <a name="run-code-analysis"></a>Executar análise de código

Na página análise de código da página de propriedades do projeto, você pode configurar a análise de código para ser executada cada vez que você compilar seu projeto. Você também pode executar a análise de código manualmente.

Para executar a análise de código em uma solução:

- No menu **Compilar** , escolha **executar análise de código na solução**.

Para executar a análise de código em um projeto:

1. Na Gerenciador de Soluções, selecione o nome do projeto.

1. No menu **Compilar** , escolha **executar análise de código no** *nome do projeto*.

Para executar a análise de código em um arquivo:

1. Na Gerenciador de Soluções, selecione o nome do arquivo.

1. No menu **Compilar** , escolha **executar análise de código no arquivo** ou pressione **Ctrl + Shift + Alt + F7**.

   O projeto ou solução é compilado e a análise de código é executada. Os resultados aparecem na Lista de Erros.

## <a name="analyze-and-resolve-code-analysis-warnings"></a>Analisar e resolver avisos de análise de código

Para analisar um aviso específico, escolha o título do aviso no Lista de Erros. O aviso se expande para exibir informações adicionais sobre o problema. Quando possível, a análise de código exibe os números de linha e a lógica de análise que levaram ao aviso. Para obter informações detalhadas sobre o aviso, incluindo possíveis soluções para o problema, escolha a ID de aviso para exibir seu tópico de ajuda online correspondente.

Quando você seleciona um aviso, a linha de código que causou o aviso é realçada no editor de código do Visual Studio.

Depois de entender o problema, você pode resolvê-lo no seu código. Em seguida, execute novamente a análise de código para certificar-se de que o aviso não aparecerá mais na Lista de Erros e que sua correção não gerou nenhum aviso novo.

## <a name="suppress-code-analysis-warnings"></a>Suprimir avisos de análise de código

Há ocasiões em que você pode decidir não corrigir um aviso de análise de código. Você pode decidir que resolver o aviso exige recodificação demais considerando a probabilidade de que o problema ocorrerá em qualquer implementação do seu código no mundo real. Ou você pode achar que a análise usada no aviso é inadequada nesse contexto específico. Você pode suprimir avisos individuais para que eles não apareçam mais no Lista de Erros.

### <a name="to-suppress-a-warning"></a>Para suprimir um aviso

1. Se as informações detalhadas não forem exibidas, escolha o título do aviso para expandi-la.

1. Escolha o link **Ações** na parte inferior do aviso.

1. Escolha **suprimir mensagem** e, em seguida, escolha **na fonte**.

   Suprimir uma mensagem insere `#pragma warning (disable:[warning ID])` que suprime o aviso para a linha de código.

## <a name="create-work-items-for-code-analysis-warnings"></a>Criar itens de trabalho para avisos de análise de código

Você pode usar o recurso de acompanhamento de item de trabalho para registrar bugs de dentro do Visual Studio. Para usar esse recurso, você deve se conectar a uma instância do Team Foundation Server.

### <a name="to-create-a-work-item-for-one-or-more-cc-code-warnings"></a>Para criar um item de trabalho para um ou mais avisosC++ C/Code

1. Na Lista de Erros, expanda e selecione os avisos

1. No menu de atalho para os avisos, escolha **Criar item de trabalho**e, em seguida, escolha o tipo de item de trabalho.

1. O Visual Studio cria um único item de trabalho para os avisos selecionados e exibe o item de trabalho em uma janela de documento do IDE.

1. Adicione informações adicionais e, em seguida, escolha **salvar item de trabalho**.

## <a name="search-and-filter-code-analysis-results"></a>Pesquisar e filtrar resultados da análise de código

{1&gt;Você pode pesquisar listas longas de mensagens de aviso e filtrar avisos em soluções multiprojeto.&lt;1}

- **Para filtrar avisos por ID de aviso ou título**: Insira a palavra-chave na caixa de pesquisa.

- **Para filtrar avisos por severidade**: por padrão, as mensagens de análise de código recebem uma severidade de **aviso**. Você pode atribuir a severidade de uma ou mais mensagens como **erro** em um conjunto de regras personalizadas. Na coluna **severidade** da **lista de erros**, escolha a seta suspensa e, em seguida, o ícone de filtro. Escolha **aviso** ou **erro** para exibir apenas as mensagens que recebem a respectiva severidade. Escolha **selecionar tudo** para exibir todas as mensagens.

## <a name="see-also"></a>Confira também

- [Análise de código para C/C++](../code-quality/code-analysis-for-c-cpp-overview.md)
