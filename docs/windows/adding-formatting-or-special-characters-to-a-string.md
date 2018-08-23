---
title: Adicionando formatação ou caracteres especiais em uma cadeia de caracteres | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- special characters, adding to strings
- ASCII characters, adding to strings
- strings [C++], formatting
- strings [C++], special characters
ms.assetid: c40f394a-8b2c-4896-ab30-6922863ddbb5
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: f3c9623e151dc552ae5a1e5c5da65e62065edf5b
ms.sourcegitcommit: 6f8dd98de57bb80bf4c9852abafef1c35a7600f1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/22/2018
ms.locfileid: "42602227"
---
# <a name="adding-formatting-or-special-characters-to-a-string"></a>Adicionando formatação ou caracteres especiais a uma cadeia de caracteres

### <a name="to-add-formatting-or-special-characters-to-a-string"></a>Para adicionar formatação ou caracteres especiais em uma cadeia de caracteres

1. Abra a tabela de cadeia de caracteres clicando duas vezes em seu ícone no [exibição de recurso](../windows/resource-view-window.md).

   > [!NOTE]
   > Se seu projeto já não contiver um arquivo. RC, consulte [criando um novo arquivo de Script de recurso](../windows/how-to-create-a-resource-script-file.md).

2. Selecione a cadeia de caracteres que você deseja modificar.

3. No [janela de propriedades](/visualstudio/ide/reference/properties-window), adicione qualquer uma das sequências de escape padrão listados abaixo para o texto na **legenda** caixa e pressione **Enter**.

   |Para obter isso|Digite isto|
   |-----------------|---------------|
   |Nova linha|\n|
   |Retorno de carro|\r|
   |Tabulação|\t|
   |Barra invertida (\\)|\\\|
   |Caractere ASCII|\ddd (notação octal)|
   |alerta (sino)|\a|

> [!NOTE]
> O **cadeia de caracteres** editor não oferece suporte para o conjunto completo de caracteres de escape ASCI. Você pode usar apenas aqueles listados acima.

Para obter informações sobre como adicionar recursos a projetos gerenciados (aquelas que visam o common language runtime), consulte [recursos em aplicativos de área de trabalho](/dotnet/framework/resources/index) na *guia do desenvolvedor do .NET Framework*. Para obter informações sobre como adicionar manualmente os arquivos de recursos a projetos gerenciados, acessar recursos, exibir recursos estáticos e atribuir cadeias de caracteres de recursos a propriedades, consulte [instruções passo a passo: Localizando Windows Forms](http://msdn.microsoft.com/9a96220d-a19b-4de0-9f48-01e5d82679e5) e [Passo a passo: usando recursos para localização com o ASP.NET](http://msdn.microsoft.com/Library/bb4e5b44-e2b0-48ab-bbe9-609fb33900b6).

## <a name="requirements"></a>Requisitos

Win32

## <a name="see-also"></a>Consulte também

[Editor de cadeias de caracteres](../windows/string-editor.md)  