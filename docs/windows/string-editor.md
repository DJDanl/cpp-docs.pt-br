---
title: Editor de cadeia de caracteres | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: conceptual
f1_keywords:
- vc.editors.string.F1
dev_langs:
- C++
helpviewer_keywords:
- String editor
- string tables
- string tables, String editor
- string editing
- string editing, string tables
- resource editors, String editor
- strings [C++], editing
ms.assetid: f71ab8de-3068-4e29-8e28-5a33d18dd416
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 51470a572ec9540f203bb4cff80981fe6ad15dd1
ms.sourcegitcommit: 6f8dd98de57bb80bf4c9852abafef1c35a7600f1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/22/2018
ms.locfileid: "42578565"
---
# <a name="string-editor"></a>Editor de Cadeia de Caracteres

Uma tabela de cadeia de caracteres é um recurso do Windows que contém uma lista de IDs, valores e as legendas para todas as cadeias de caracteres do seu aplicativo. Por exemplo, os prompts de barra de status estão localizados na tabela de cadeia de caracteres.

Ao desenvolver um aplicativo, você pode ter várias tabelas de cadeia de caracteres — uma para cada idioma ou a condição. No entanto, um módulo executável tem apenas uma tabela de cadeia de caracteres. Um aplicativo em execução pode fazer referência a várias tabelas de cadeia de caracteres se você colocar as tabelas em DLLs diferentes.

Tabelas de cadeia de caracteres tornam fácil localizar seu aplicativo em diferentes idiomas. Se todas as cadeias de caracteres estão em uma tabela de cadeia de caracteres, você pode localizar o aplicativo, convertendo as cadeias de caracteres (e outros recursos) sem alterar o código-fonte. Isso é geralmente mais desejável do que manualmente Localizando e substituindo várias cadeias de caracteres em arquivos de origem.

Usando o editor de cadeia de caracteres, você pode:

- [Pesquisar um ou mais cadeias de caracteres](../windows/finding-a-string.md).

- Rapidamente [inserir novas entradas](../windows/adding-or-deleting-a-string.md) na tabela de cadeia de caracteres.

- [Mover uma cadeia de caracteres de um arquivo de recurso para outro](../windows/moving-a-string-from-one-resource-file-to-another.md)

- [Use a edição in-loco para as propriedades de ID, o valor e a legenda](../windows/changing-the-properties-of-a-string.md) e exibir as alterações imediatamente.

- [Alterar a propriedade de legenda de várias cadeias de caracteres](../windows/changing-the-caption-property-of-multiple-strings.md)

- [Adicione formatação ou caracteres especiais em uma cadeia de caracteres](../windows/adding-formatting-or-special-characters-to-a-string.md)

   > [!NOTE]
   > Windows não permitem a criação de tabelas de cadeia de caracteres vazia. Se você criar uma tabela de cadeia de caracteres sem entradas, ele é excluído automaticamente quando você salvar o arquivo de recurso.

Para obter informações sobre como adicionar recursos a projetos gerenciados (aquelas que visam o common language runtime), consulte [recursos em aplicativos de área de trabalho](/dotnet/framework/resources/index) na *guia do desenvolvedor do .NET Framework*. Para obter informações sobre como adicionar manualmente os arquivos de recursos a projetos gerenciados, acessar recursos, exibir recursos estáticos e atribuir cadeias de caracteres de recursos a propriedades, consulte [instruções passo a passo: Localizando Windows Forms](http://msdn.microsoft.com/9a96220d-a19b-4de0-9f48-01e5d82679e5) e [Passo a passo: usando recursos para localização com o ASP.NET](http://msdn.microsoft.com/Library/bb4e5b44-e2b0-48ab-bbe9-609fb33900b6).

## <a name="requirements"></a>Requisitos

Win32

## <a name="see-also"></a>Consulte também

[Editores de recursos](../windows/resource-editors.md)  
[Cadeias de Caracteres](http://msdn.microsoft.com/library/windows/desktop/ms646979.aspx)  
[Sobre cadeias de caracteres](/windows/desktop/menurc/about-strings)

