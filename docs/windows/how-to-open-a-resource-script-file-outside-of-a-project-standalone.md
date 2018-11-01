---
title: 'Como: abrir um arquivo de Script de recurso fora de um projeto do C++ (autônomo)'
ms.date: 11/04/2016
f1_keywords:
- vc.editors.resource
helpviewer_keywords:
- resources [C++], viewing
- rc files [C++], viewing resources
- .rc files [C++], viewing resources
- resource script files [C++], viewing resources
ms.assetid: bc350c60-178d-4c5d-9a7e-6576b0c936e4
ms.openlocfilehash: 43b245c1d19e7468a9433473eb49dc970316eba5
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50529071"
---
# <a name="how-to-open-a-resource-script-file-outside-of-a-c-project-standalone"></a>Como: abrir um arquivo de Script de recurso fora de um projeto do C++ (autônomo)

Você pode exibir recursos em um arquivo. rc sem a necessidade de abrir um projeto. O arquivo. RC será aberto em uma janela de documento em vez de abertura na [exibição de recurso](../windows/resource-view-window.md) janela (como quando o arquivo é aberto dentro de um projeto).

> [!NOTE]
> Isso é uma distinção importante porque alguns comandos estão disponíveis somente quando o arquivo é aberto autônomo (fora de um projeto). Por exemplo, você só pode salvar um arquivo em um formato diferente ou como um nome de arquivo diferentes quando o arquivo é aberto fora de um projeto (o **Salvar como** comando não está disponível quando um arquivo é aberto dentro de um projeto).

### <a name="to-open-an-rc-file-outside-a-project"></a>Para abrir um arquivo. rc fora de um projeto

1. Do **arquivo** menu, escolha **aberto**, em seguida, clique em **arquivo**.

2. No **abrir arquivo** diálogo caixa, navegue até o arquivo de script de recurso que você deseja exibir, realce o arquivo e clique em **abrir**.

   > [!NOTE]
   > Se você abrir o projeto pela primeira vez (**arquivo**, **abra**, **projeto**), alguns comandos não estarão disponíveis para você. Abrir um arquivo "autônomo" significa abri-lo sem primeiro carregar o projeto.

Para abrir e exibir o arquivo de recurso no formato de texto, consulte [editando um Script de recurso (. rc) arquivo](../windows/how-to-open-a-resource-script-file-in-text-format.md).

### <a name="to-open-multiple-rc-files-outside-a-project"></a>Para abrir vários arquivos. rc fora de um projeto

1. Abra ambos os arquivos de recurso autônomos. Por exemplo, abra `Source1.rc` e `Source2.rc`.

   1. Do **arquivo** menu, escolha **aberto**, em seguida, clique em **arquivo**.

   2. No **abrir arquivo** diálogo caixa, navegue até o primeiro arquivo de script de recurso que deseja abrir (`Source1.rc`), realce o arquivo e clique em **abrir**.

   3. Repita a etapa anterior para abrir o segundo arquivo. RC (`Source2.rc`).

       Os arquivos. rc agora estão abertos em janelas de documentos separada.

2. Quando ambos os arquivos. rc estão abertos, lado a lado as janelas para que você pode exibir simultaneamente:

   - Dos **janela** menu, escolha **novo grupo de guias horizontais** ou **novo grupo de guias verticais**.

       \- ou -

   - Clique em um dos arquivos. RC e escolha **novo grupo de guias horizontais** ou **novo grupo de guias verticais** no menu de atalho.

> [!NOTE]
> Se seu projeto já não contiver um arquivo. RC, consulte [criando um novo arquivo de Script de recurso](../windows/how-to-create-a-resource-script-file.md).

## <a name="requirements"></a>Requisitos

Win32

## <a name="see-also"></a>Consulte também

[Arquivos de recurso](../windows/resource-files-visual-studio.md)<br/>
[Editores de recursos](../windows/resource-editors.md)