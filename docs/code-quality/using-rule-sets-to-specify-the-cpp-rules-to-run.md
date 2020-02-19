---
title: Usando conjuntos de regras para especificar as regras do C++ para execução
ms.date: 04/28/2018
ms.topic: conceptual
f1_keywords:
- vs.codeanalysis.rulesets.native
ms.openlocfilehash: 5cf0f88c6937f4c1609a29fd618af0fdadad4437
ms.sourcegitcommit: 7bea0420d0e476287641edeb33a9d5689a98cb98
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/17/2020
ms.locfileid: "77418714"
---
# <a name="use-rule-sets-to-specify-the-c-rules-to-run"></a>Usar conjuntos de regras para especificar C++ as regras a serem executadas

No Visual Studio, você pode criar e modificar um *conjunto de regras* personalizadas para atender às necessidades específicas do projeto associadas à análise de código. Os conjuntos de regras padrão são armazenados em `%VSINSTALLDIR%\Team Tools\Static Analysis Tools\Rule Sets`.

**Visual Studio 2017 versão 15,7 e posterior:** Você pode criar conjuntos de regras personalizados usando qualquer editor de texto e aplicá-los em compilações de linha de comando, independentemente do sistema de compilação que você está usando. Para obter mais informações, consulte [/analyze: RuleSet](/cpp/build/reference/analyze-code-analysis).

Para criar um conjunto C++ de regras personalizado no Visual Studio, um CC++ /projeto deve estar aberto no IDE do Visual Studio. Em seguida, abra um conjunto de regras padrão no editor de conjunto de regras e adicione ou remova regras específicas e, opcionalmente, altere a ação que ocorre quando a análise de código determina que uma regra foi violada.

Para criar um novo conjunto de regras personalizadas, salve-o usando um novo nome de arquivo. O conjunto de regras personalizadas é atribuído automaticamente ao projeto.

## <a name="to-create-a-custom-rule-from-a-single-existing-rule-set"></a>Para criar uma regra personalizada com base em um único conjunto de regras existente

1. No Gerenciador de Soluções, abra o menu de atalho do projeto e, em seguida, escolha **Propriedades**.

1. Na guia **Propriedades** , escolha **análise de código**.

1. Na lista suspensa **conjunto de regras** , siga um destes procedimentos:

   - Escolha o conjunto de regras que você deseja personalizar.

     \- ou –

   - Escolha **\<procurar... >** especificar um conjunto de regras existente que não esteja na lista.

1. Escolha **abrir** para exibir as regras no editor de conjunto de regras.

## <a name="to-modify-a-rule-set-in-the-rule-set-editor"></a>Para modificar um conjunto de regras no editor de conjunto de regras

- Para alterar o nome de exibição do conjunto de regras, no menu **Exibir** , escolha **janela de propriedades**. Insira o nome de exibição na caixa **nome** . Observe que o nome de exibição pode ser diferente do nome do arquivo.

- Para adicionar todas as regras do grupo a um conjunto de regras personalizadas, marque a caixa de seleção do grupo. Para remover todas as regras do grupo, desmarque a caixa de seleção.

- Para adicionar uma regra específica ao conjunto de regras personalizadas, marque a caixa de seleção da regra. Para remover a regra do conjunto de regras, desmarque a caixa de seleção.

- Para alterar a ação realizada quando uma regra é violada em uma análise de código, escolha o campo de **ação** para a regra e, em seguida, escolha um dos seguintes valores:

     **Aviso** -gera um aviso.

     **Erro** -gera um erro.

     **Informações** – gera uma mensagem.

     **Nenhum** – desabilita a regra. Essa ação é a mesma que remover a regra do conjunto de regras.

## <a name="to-group-filter-or-change-the-fields-in-the-rule-set-editor-by-using-the-rule-set-editor-toolbar"></a>Para agrupar, filtrar ou alterar os campos no editor de conjunto de regras usando a barra de ferramentas do editor de conjunto de regras

- Para expandir as regras em todos os grupos, escolha **expandir tudo**.

- Para recolher as regras em todos os grupos, escolha **recolher tudo**.

- Para alterar o campo pelo qual as regras são agrupadas, escolha o campo na lista **Agrupar por** . Para exibir as regras desagrupadas, escolha **\<nenhum >** .

- Para adicionar ou remover campos em colunas de regra, escolha **Opções de coluna**.

- Para ocultar regras que não se aplicam à solução atual, escolha **ocultar regras que não se aplicam à solução atual**.

- Para alternar entre mostrar e ocultar regras que são atribuídas à ação de erro, escolha **Mostrar regras que podem gerar erros de análise de código**.

- Para alternar entre mostrar e ocultar regras que recebem a ação de aviso, escolha **Mostrar regras que podem gerar avisos de análise de código**.

- Para alternar entre mostrar e ocultar regras que são atribuídas à ação **nenhum** , escolha **Mostrar regras que não estão habilitadas**.

- Para adicionar ou remover conjuntos de regras padrão da Microsoft para o conjunto de regras atual, escolha **Adicionar ou remover conjuntos de regras filho**.

## <a name="to-create-a-rule-set-in-a-text-editor"></a>Para criar um conjunto de regras em um editor de texto

Você pode criar um conjunto de regras personalizado em um editor de texto, armazená-lo em qualquer local com uma extensão `.ruleset` e aplicá-lo com a opção de compilador [/analyze: RuleSet](/cpp/build/reference/analyze-code-analysis) .

O exemplo a seguir mostra um arquivo de conjunto de regras básico que você pode usar como um ponto de partida:

::: moniker range="<=vs-2017"

```xml
<?xml version="1.0" encoding="utf-8"?>
<RuleSet Name="New Rule Set" Description=" " ToolsVersion="15.0">
  <Rules AnalyzerId="Microsoft.Analyzers.NativeCodeAnalysis" RuleNamespace="Microsoft.Rules.Native">
    <Rule Id="C6001" Action="Warning" />
    <Rule Id="C26494" Action="Warning" />
  </Rules>
</RuleSet>
```

::: moniker-end

::: moniker range=">=vs-2019"

```xml
<?xml version="1.0" encoding="utf-8"?>
<RuleSet Name="New Rule Set" Description=" " ToolsVersion="16.0">
  <Rules AnalyzerId="Microsoft.Analyzers.NativeCodeAnalysis" RuleNamespace="Microsoft.Rules.Native">
    <Rule Id="C6001" Action="Warning" />
    <Rule Id="C26494" Action="Warning" />
  </Rules>
</RuleSet>
```

::: moniker-end
