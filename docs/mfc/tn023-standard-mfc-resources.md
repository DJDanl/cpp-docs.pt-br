---
title: 'TN023: recursos MFC padrão'
ms.date: 11/04/2016
helpviewer_keywords:
- resources [MFC]
- TN023
- standard resources
ms.assetid: 60af8415-c576-4c2f-a711-ca5da0b9a1f2
ms.openlocfilehash: 90e7b9b7c354ba919c3dee279725b4498bea57ff
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81370378"
---
# <a name="tn023-standard-mfc-resources"></a>TN023: recursos MFC padrão

Esta nota descreve os recursos padrão fornecidos e necessários pela biblioteca MFC.

## <a name="standard-resources"></a>Recursos padrão

O MFC oferece duas categorias de recursos predefinidos que você pode usar em sua aplicação: recursos de clip-art e recursos de estrutura padrão.

Os recursos de clip-art são recursos adicionais dos quais a estrutura não depende, mas que você pode querer adicionar à interface de usuário do seu aplicativo. Os seguintes recursos de clip-art estão contidos na amostra geral do MFC [CLIPART](../overview/visual-cpp-samples.md):

- Common.rc: Um único arquivo de recursos que contém:

  - Uma grande coleção de ícones que representam uma variedade de tarefas de negócios e processamento de dados.

  - Vários cursores comuns (veja também Afxres.rc).

  - Um bitmap da barra de ferramentas que contém vários botões da barra de ferramentas.

  - Os recursos de bitmap e ícone que são usados pelo Commdlg.dll.

- Indique.rc: Contém recursos de string para os indicadores de estado-chave da barra de status, como "CAP" para Caps Lock.

- Prompts.rc: Contém recursos de seqüência de comando sinuosos para cada comando predefinido, como "Criar um novo documento" para ID_FILE_NEW.

- Commdlg.rc: Um arquivo .rc compatível com Visual C++ que contém os modelos de diálogo COMMDLG padrão.

Os recursos-quadro padrão são recursos com IDs definidos pelo AFX que o framework depende para implementações internas. Você raramente precisará alterar esses recursos definidos pelo AFX. Se você fizer isso, você deve seguir o procedimento descrito mais tarde neste tópico.

Os seguintes recursos-quadro estão contidos no diretório MFC\INCLUDE:

- Afxres.rc: Recursos comuns utilizados pela estrutura.

- Afxprint.rc: Recursos específicos para impressão.

- Afxolecl.rc: Recursos específicos para aplicações cliente OLE.

- Afxolev.rc: Recursos específicos para aplicativos completos de servidor OLE.

## <a name="using-clip-art-resources"></a>Usando recursos de clip-art

#### <a name="to-use-a-clip-art-binary-resource"></a>Para usar um recurso binário de clip-art

1. Abra o arquivo de recursos do seu aplicativo no Visual C++.

1. Open Common.rc. Este arquivo contém todos os recursos binários de clip-art. Isso pode levar algum tempo porque o arquivo Common.rc é compilado.

1. Mantenha a CTRL baixa enquanto você arrasta os recursos que deseja usar do Common.rc para o arquivo de recursos do aplicativo.

Para usar outros recursos de clip-art, siga os mesmos passos. A única diferença é que você abrirá o arquivo .rc apropriado em vez de Common.rc.

> [!NOTE]
> Tenha cuidado para não mover involuntariamente recursos para fora do Common.rc permanentemente. Se você segurar a tecla CTRL enquanto arrasta recursos, você criará uma cópia. Se você não segurar CTRL para baixo enquanto você arrasta, os recursos serão movidos. Se você estiver preocupado que você possa ter acidentalmente feito alterações no arquivo Common.rc, clique em "Não" quando for perguntado se deve salvar as alterações em Common.rc.

> [!NOTE]
> Os arquivos de recursos .rc têm um recurso TEXTINCLUDE especial neles que impedirá que você economize acidentalmente em cima dos arquivos .rc padrão.

### <a name="customizing-standard-framework-resources"></a>Personalização dos recursos-quadro padrão

Os recursos de estrutura padrão geralmente são incluídos em um aplicativo usando o comando #include no arquivo de recursos de um aplicativo. O AppWizard gerará um arquivo de recursos. Este arquivo inclui os recursos de estrutura padrão apropriados, dependendo das opções do AppWizard selecionadas. Você pode rever, adicionar ou remover quais recursos estão incluídos alterando as diretivas de tempo de compilação. Para isso, abra o menu **Recurso** e selecione **Incluir conjuntos**. Veja o item de edição "Compile-Time". Por exemplo:

```
#include "afxres.rc"
#include "afxprint.rc"
```

O caso mais comum de personalização de recursos de estrutura padrão é adicionar ou remover inclui adicionais para impressão, cliente OLE e suporte ao Servidor OLE.

Em alguns casos raros, você pode querer personalizar o conteúdo dos recursos de estrutura padrão para o seu aplicativo específico, não apenas adicionar e remover todo o arquivo. As etapas a seguir mostram como você pode limitar os recursos incluídos:

##### <a name="to-customize-the-contents-of-a-standard-resource-file"></a>Para personalizar o conteúdo de um arquivo de recurso padrão

1. Abra o arquivo de recursos no Visual C++.

1. Usando o comando 'Inclui conjunto `#include` de recursos', remova o arquivo .rc padrão que você deseja personalizar. Por exemplo, para personalizar a barra de `#include "afxprint.rc"` ferramentas de visualização de impressão, remova a linha.

1. Abra os arquivos de recursos padrão apropriados no MFC\INCLUDE. Seguindo o exemplo anterior neste tópico, o arquivo apropriado é MFC\Include\Aafxprint.rc

1. Copie todos os recursos do arquivo padrão .rc para o arquivo de recursos do aplicativo.

1. Modifique a cópia dos recursos padrão no arquivo de recursos do aplicativo.

> [!NOTE]
> Não modifique os recursos diretamente nos arquivos padrão .rc. Isso modificará os recursos disponíveis em cada aplicativo, não apenas no que você está trabalhando atualmente.

## <a name="see-also"></a>Confira também

[Observações técnicas por número](../mfc/technical-notes-by-number.md)<br/>
[Observações técnicas por categoria](../mfc/technical-notes-by-category.md)
