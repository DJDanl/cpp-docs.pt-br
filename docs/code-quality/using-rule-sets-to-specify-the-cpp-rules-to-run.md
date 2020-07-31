---
title: Usando conjuntos de regras para especificar as regras do C++ para execução
ms.date: 07/27/2020
ms.topic: conceptual
f1_keywords:
- vs.codeanalysis.rulesets.native
ms.openlocfilehash: b132400485c041b96e81736bcda04922b2cda88c
ms.sourcegitcommit: 6e55aeb538b1c39af754f82d6f7738a18f5aa031
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/29/2020
ms.locfileid: "87389812"
---
# <a name="use-rule-sets-to-specify-the-c-rules-to-run"></a>Usar conjuntos de regras para especificar as regras do C++ para execução

No Visual Studio, você pode criar e modificar um *conjunto de regras* personalizadas para atender às necessidades específicas do projeto associadas à análise de código. Os conjuntos de regras padrão são armazenados em *`%VSINSTALLDIR%\Team Tools\Static Analysis Tools\Rule Sets`* .

**Visual Studio 2017 versão 15,7 e posterior:** Você pode criar conjuntos de regras personalizados usando qualquer editor de texto e aplicá-los em compilações de linha de comando, independentemente do sistema de compilação que você está usando. Para obter mais informações, consulte [`/analyze:ruleset`](/cpp/build/reference/analyze-code-analysis).

Para criar um conjunto personalizado de regras do C++ no Visual Studio, um projeto C/C++ deve estar aberto no IDE do Visual Studio. Em seguida, abra um conjunto de regras padrão no editor de conjunto de regras e adicione ou remova regras específicas e, opcionalmente, altere a ação que ocorre quando a análise de código determina que uma regra foi violada.

Para criar um novo conjunto de regras personalizadas, salve-o usando um novo nome de arquivo. O conjunto de regras personalizadas é atribuído automaticamente ao projeto.

## <a name="to-create-a-custom-rule-from-a-single-existing-rule-set"></a>Para criar uma regra personalizada com base em um único conjunto de regras existente

::: moniker range="<=vs-2017"

1. No Gerenciador de Soluções, abra o menu de atalho do projeto e, em seguida, escolha **Propriedades**.

1. Na caixa de diálogo **páginas de propriedades** , selecione a página de propriedades **configuração** > **análise de código** > **geral** .

1. Na lista suspensa **conjunto de regras** , siga um destes procedimentos:

   - Escolha o conjunto de regras que você deseja personalizar.

     \- ou –

   - Escolha **\<Browse...>** especificar um conjunto de regras existente que não esteja na lista.

1. Escolha **abrir** para exibir as regras no editor de conjunto de regras.

::: moniker-end
::: moniker range=">=vs-2019"

1. No Gerenciador de Soluções, abra o menu de atalho do projeto e, em seguida, escolha **Propriedades**.

1. Na caixa de diálogo **páginas de propriedades** , selecione a página de propriedades **configuração** > **análise de código** da > **Microsoft** .

1. Na lista suspensa **regras ativas** , siga um destes procedimentos:

   - Escolha o conjunto de regras que você deseja personalizar.

     \- ou –

   - Escolha **\<Browse...>** especificar um conjunto de regras existente que não esteja na lista.

1. Escolha **abrir** para exibir as regras no editor de conjunto de regras.

::: moniker-end

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

- Para alterar o campo pelo qual as regras são agrupadas, escolha o campo na lista **Agrupar por** . Para exibir as regras desagrupadas, escolha **\<None>** .

- Para adicionar ou remover campos em colunas de regra, escolha **Opções de coluna**.

- Para ocultar regras que não se aplicam à solução atual, escolha **ocultar regras que não se aplicam à solução atual**.

- Para alternar entre mostrar e ocultar regras que são atribuídas à ação de erro, escolha **Mostrar regras que podem gerar erros de análise de código**.

- Para alternar entre mostrar e ocultar regras que recebem a ação de aviso, escolha **Mostrar regras que podem gerar avisos de análise de código**.

- Para alternar entre mostrar e ocultar regras que são atribuídas à ação **nenhum** , escolha **Mostrar regras que não estão habilitadas**.

- Para adicionar ou remover conjuntos de regras padrão da Microsoft para o conjunto de regras atual, escolha **Adicionar ou remover conjuntos de regras filho**.

## <a name="to-create-a-rule-set-in-a-text-editor"></a>Para criar um conjunto de regras em um editor de texto

Você pode criar um conjunto de regras personalizado em um editor de texto, armazená-lo em qualquer local com uma *`.ruleset`* extensão e aplicá-lo com a [`/analyze:ruleset`](/cpp/build/reference/analyze-code-analysis) opção do compilador.

O exemplo a seguir mostra um arquivo de conjunto de regras básico que você pode usar como um ponto de partida:

```xml
<?xml version="1.0" encoding="utf-8"?>
<RuleSet Name="New Rule Set" Description="New rules to apply." ToolsVersion="10.0">
  <Rules AnalyzerId="Microsoft.Analyzers.NativeCodeAnalysis" RuleNamespace="Microsoft.Rules.Native">
    <Rule Id="C6001" Action="Warning" />
    <Rule Id="C26494" Action="Warning" />
  </Rules>
</RuleSet>
```

## <a name="ruleset-schema"></a>Esquema do RuleSet

O esquema do conjunto de regras a seguir descreve o esquema XML de um arquivo RuleSet. O esquema do conjunto de regras é armazenado no *`%VSINSTALLDIR%\Team Tools\Static Analysis Tools\Schemas\RuleSet.xsd`* . Você pode usá-lo para criar seus próprios RuleSets programaticamente ou para validar se os RuleSets personalizados aderem ao formato correto. Para obter mais informações, consulte [como: criar um documento XML com base em um esquema XSD](https://docs.microsoft.com/visualstudio/xml-tools/how-to-create-an-xml-document-based-on-an-xsd-schema?view=vs-2019).

```xml
<?xml version="1.0" encoding="utf-8"?>
<xs:schema xmlns:xs="http://www.w3.org/2001/XMLSchema">

  <xs:annotation>
    <xs:documentation xml:lang="en">
            Visual Studio Code Analysis Rule Set Schema Definition Language.
            Copyright (c) Microsoft Corporation. All rights reserved.
        </xs:documentation>
  </xs:annotation>

  <!-- Every time this file changes, be sure to change the Validate method for the corresponding object in the code -->

  <xs:element name="RuleSet" type="TRuleSet">
  </xs:element>

  <xs:complexType name="TLocalization">
    <xs:all>
      <xs:element name="Name" type="TName" minOccurs="0" maxOccurs="1" />
      <xs:element name="Description" type="TDescription" minOccurs="0" maxOccurs="1" />
    </xs:all>
    <xs:attribute name="ResourceAssembly" type="TNonEmptyString" use="required" />
    <xs:attribute name="ResourceBaseName" type="TNonEmptyString" use="required" />
  </xs:complexType>

  <xs:complexType name="TRuleHintPaths">
    <xs:sequence>
      <xs:element name="Path" type="TNonEmptyString" minOccurs="0" maxOccurs="unbounded" />
    </xs:sequence>
  </xs:complexType>
  
  <xs:complexType name="TName">
    <xs:attribute name="Resource" type="TNonEmptyString" use="required" />
  </xs:complexType>

  <xs:complexType name="TDescription">
    <xs:attribute name="Resource" type="TNonEmptyString" use="required" />
  </xs:complexType>

  <xs:complexType name="TInclude">
    <xs:attribute name="Path" type="TNonEmptyString" use="required" />
    <xs:attribute name="Action" type="TIncludeAction" use="required" />
  </xs:complexType>

  <xs:complexType name="TIncludeAll">
    <xs:attribute name="Action" type="TIncludeAllAction" use="required" />
  </xs:complexType>

  <xs:complexType name="TRule">
    <xs:attribute name="Id" type="TNonEmptyString" use="required" />
    <xs:attribute name="Action" type="TRuleAction" use="required" />
  </xs:complexType>

  <xs:complexType name="TRules">
    <xs:sequence>
      <xs:element name="Rule" type="TRule" minOccurs="0" maxOccurs="unbounded" />
    </xs:sequence>
    <xs:attribute name="AnalyzerId" type="TNonEmptyString" use="required" />
    <xs:attribute name="RuleNamespace" type="TNonEmptyString" use="required" />
  </xs:complexType>

  <xs:complexType name="TRuleSet">
    <xs:sequence minOccurs="0" maxOccurs="1">
      <xs:element name="Localization" type="TLocalization" minOccurs="0" maxOccurs="1" />
      <xs:element name="RuleHintPaths" type="TRuleHintPaths" minOccurs="0" maxOccurs="1" />
      <xs:element name="IncludeAll" type="TIncludeAll" minOccurs="0" maxOccurs="1" />
      <xs:choice minOccurs="0" maxOccurs="unbounded">
        <xs:element name="Include" type="TInclude" minOccurs="0" maxOccurs="unbounded" />
        <xs:element name="Rules" type="TRules" minOccurs="0" maxOccurs="unbounded">
          <xs:unique name="UniqueRuleName">
            <xs:selector xpath="Rule" />
            <xs:field xpath="@Id" />
          </xs:unique>
        </xs:element>
      </xs:choice>
    </xs:sequence>
    <xs:attribute name="Name" type="TNonEmptyString" use="required" />
    <xs:attribute name="Description" type="xs:string" use="optional" />
    <xs:attribute name="ToolsVersion" type="TNonEmptyString" use="required" />
  </xs:complexType>

  <xs:simpleType name="TRuleAction">
    <xs:restriction base="xs:string">
      <xs:enumeration value="Error"/>
      <xs:enumeration value="Warning"/>
      <xs:enumeration value="Info"/>
      <xs:enumeration value="Hidden"/>
      <xs:enumeration value="None"/>
    </xs:restriction>
  </xs:simpleType>

  <xs:simpleType name="TIncludeAction">
    <xs:restriction base="xs:string">
      <xs:enumeration value="Error"/>
      <xs:enumeration value="Warning"/>
      <xs:enumeration value="Info"/>
      <xs:enumeration value="Hidden"/>
      <xs:enumeration value="None"/>
      <xs:enumeration value="Default"/>
    </xs:restriction>
  </xs:simpleType>

  <xs:simpleType name="TIncludeAllAction">
    <xs:restriction base="xs:string">
      <xs:enumeration value="Error"/>
      <xs:enumeration value="Warning"/>
      <xs:enumeration value="Info"/>
      <xs:enumeration value="Hidden"/>
    </xs:restriction>
  </xs:simpleType>

  <xs:simpleType name="TNonEmptyString">
    <xs:restriction base="xs:string">
      <xs:minLength value="1" />
    </xs:restriction>
  </xs:simpleType>
  
</xs:schema>

```

Detalhes do elemento de esquema:

| Elemento Schema | Descrição |
|--------------------|--------------|
| `TLocalization` | Informações de localização, incluindo o nome do arquivo RuleSet, a descrição do arquivo RuleSet, o nome do assembly de recurso que contém o recurso localizado e o nome de base do recurso localizado |
| `TRuleHintPaths` | Caminhos de arquivo usados como dicas para pesquisar arquivos RuleSet |
| `TName` | Nome do arquivo RuleSet atual |
| `TDescription` | Descrição do arquivo RuleSet atual |
| `TInclude` | Caminho para um conjunto de regras incluído com ação de regra |
| `TIncludeAll` | Ação de regra para todas as regras |
| `TRule` | ID da regra com ação de regra |
| `TRules` | Coleção de uma ou mais regras |
| `TRuleSet` | Formato de arquivo RuleSet que consiste em informações de localização, caminhos de dica de regra, incluir todas as informações, incluir informações, informações de regras, nome, descrição e informações de versão de ferramentas |
| `TRuleAction` | Enumeração que descreve uma ação de regra, como erro, aviso, informações, oculto ou nenhum |
| `TIncludeAction` | Enumeração que descreve uma ação de regra, como erro, aviso, informações, oculto, nenhum ou padrão |
| `TIncludeAllAction` | Enumeração que descreve uma ação de regra, como erro, aviso, informações ou oculta |

Para ver um exemplo de um RuleSet, consulte [para criar um conjunto de regras em um editor de texto](#to-create-a-rule-set-in-a-text-editor)ou qualquer um dos conjuntos de regras padrão armazenados no `%VSINSTALLDIR%\Team Tools\Static Analysis Tools\Rule Sets` .
