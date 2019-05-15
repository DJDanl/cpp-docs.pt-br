---
title: 'TN023: Recursos MFC padrão'
ms.date: 11/04/2016
helpviewer_keywords:
- resources [MFC]
- TN023
- standard resources
ms.assetid: 60af8415-c576-4c2f-a711-ca5da0b9a1f2
ms.openlocfilehash: b6a1978a92fcf53de7caacd41c01a91ff16a3fc3
ms.sourcegitcommit: 934cb53fa4cb59fea611bfeb9db110d8d6f7d165
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/14/2019
ms.locfileid: "65611410"
---
# <a name="tn023-standard-mfc-resources"></a>TN023: Recursos MFC padrão

Essa observação descreve os recursos padrão fornecido com e necessárias para a biblioteca MFC.

## <a name="standard-resources"></a>Recursos padrão

MFC oferece duas categorias de recursos predefinidos que você pode usar em seu aplicativo: recursos de clip-arts e recursos de estrutura padrão.

Clip-arts são recursos adicionais que o framework dependem, mas que talvez você queira adicionar a interface do usuário do seu aplicativo. Os seguintes recursos de clip-arts estão contidos na amostra gerais MFC [clip-art](../overview/visual-cpp-samples.md):

- Common.rc: Um único arquivo de recursos que contém:

   - Uma grande coleção de ícones que representam uma variedade de tarefas de processamento de dados e de negócios.

   - Vários cursores comuns (Consulte também afxres).

   - Um bitmap de barra de ferramentas que contém vários botões de barra de ferramentas.

   - Os recursos de ícone e bitmap que são usados por Commdlg.

- Indicate.rc: Contém recursos de cadeia de caracteres para os indicadores de estado da tecla de barra de status, como "Limite" a tecla Caps Lock.

- Prompts.RC: Contém recursos de cadeia de caracteres de prompt de menu para cada comando predefinido, como "Criar um novo documento" para ID_FILE_NEW.

- Commdlg.rc: Um arquivo. rc compatível do Visual C++ que contém os modelos de caixa de diálogo COMMDLG padrão.

Recursos padrão do framework são recursos com IDs definidos pelo AFX que o framework depende para implementações internas. Raramente, você precisará alterar esses recursos definidos pelo AFX. Se você fizer isso, você deve seguir o procedimento descrito neste tópico.

Os seguintes recursos de estrutura são contidos no diretório MFC\INCLUDE:

- Afxres.rc: Recursos comuns usados pela estrutura.

- Afxprint.rc: Recursos específicos de impressão.

- Afxolecl.rc: Recursos específicos de aplicativos de cliente OLE.

- Afxolev.rc: Recursos específicos de aplicativos de servidor completos OLE.

## <a name="using-clip-art-resources"></a>Usando recursos de Clip-Art

#### <a name="to-use-a-clip-art-binary-resource"></a>Para usar um recurso binário de clip-art

1. Abra o arquivo de recurso do seu aplicativo no Visual C++.

1. Abra Common.rc. Esse arquivo contém todos os recursos do binário clip-arts. Isso pode levar algum tempo, porque o arquivo Common.rc é compilado.

1. Mantenha pressionada a tecla CTRL enquanto você arrasta os recursos que você deseja usar na Common.rc ao arquivo de recurso do seu aplicativo.

Para usar outros recursos de clip-art, siga as mesmas etapas. A única diferença é que você irá abrir o arquivo. rc apropriado em vez de Common.rc.

> [!NOTE]
>  Tenha cuidado para não acidentalmente, mover os recursos fora do Common.rc permanentemente. Se você mantiver a tecla CTRL enquanto você arrasta os recursos, você criará uma cópia. Se você não Segure a tecla CTRL enquanto arrasta, os recursos serão movidos. Se você estiver preocupado que você pode ter acidentalmente feito alterações no arquivo Common.rc, clique em "Não" quando for perguntado se deseja salvar as alterações Common.rc.

> [!NOTE]
>  Os arquivos de recurso. RC tem um recurso TEXTINCLUDE especial que vai impedir que você acidentalmente salvando sobre os arquivos. rc padrão.

### <a name="customizing-standard-framework-resources"></a>Personalizando recursos padrão do Framework

Recursos padrão do framework geralmente são incluídos em um aplicativo usando o #include comando no arquivo de recurso do aplicativo. O AppWizard irá gerar um arquivo de recurso. Este arquivo inclui os recursos de estrutura padrão apropriado, dependendo de quais opções de AppWizard você selecionar. Você pode revisar, adicionar ou remover a quais recursos estão incluídos, alterando as diretivas de tempo de compilação. Para fazer isso, abra o **Resource** menu e selecione **Set Includes**. Examinar o item de editar "Diretivas de tempo de compilação". Por exemplo:

```
#include "afxres.rc"
#include "afxprint.rc"
```

O caso mais comum de personalizar recursos padrão do framework está adicionando ou removendo adicionais inclui para impressão, cliente OLE e suporte de servidor OLE.

Em alguns casos raros, que talvez você queira personalizar o conteúdo de recursos padrão do framework para seu aplicativo específico, não apenas adicionar e remover o arquivo inteiro. As etapas a seguir mostram como você pode limitar os recursos que estão incluídos:

##### <a name="to-customize-the-contents-of-a-standard-resource-file"></a>Para personalizar o conteúdo de um arquivo de recurso padrão

1. Abra o arquivo de recurso no Visual C++.

1. Usando o comando Resource Set Includes, remova o `#include` para o arquivo. rc padrão que você deseja personalizar. Por exemplo, para personalizar a barra de ferramentas de visualização de impressão, remova o `#include "afxprint.rc"` linha.

1. Abra os arquivos de recursos padrão apropriados no MFC\INCLUDE. Seguindo o exemplo neste tópico, o arquivo apropriado é MFC\Include\Aafxprint.rc

1. Copie todos os recursos do arquivo. rc padrão ao arquivo de recurso de aplicativo.

1. Modificar a cópia dos recursos standard em seu arquivo de recurso do aplicativo.

> [!NOTE]
>  Não modifique os recursos diretamente nos arquivos. rc padrão. Ao fazer isso, você modificará os recursos disponíveis em todos os aplicativos, não apenas naquele que você está trabalhando atualmente.

## <a name="see-also"></a>Consulte também

[Observações técnicas por número](../mfc/technical-notes-by-number.md)<br/>
[Observações técnicas por categoria](../mfc/technical-notes-by-category.md)
