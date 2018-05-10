---
title: 'Símbolos: Identificadores de recurso | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: conceptual
f1_keywords:
- vc.editors.symbol.identifiers
dev_langs:
- C++
helpviewer_keywords:
- symbols, resource identifiers
- symbols, creating
- resource symbols
- symbols, editing
- resource editors, resource symbols
ms.assetid: 8fccc09a-0237-4a65-b9c4-57d60c59e324
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: c049aa192aeb253641ab473e5675b1ee5bd685a6
ms.sourcegitcommit: d55ac596ba8f908f5d91d228dc070dad31cb8360
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/08/2018
---
# <a name="symbols-resource-identifiers"></a>Símbolos: Identificadores de recursos
Um símbolo é um identificador de recurso (ID) que consiste em duas partes: uma cadeia de texto (nome de símbolo) mapeada para um valor inteiro (valor de símbolo). Por exemplo:  
  
```  
IDC_EDITNAME = 5100  
```  
  
 Nomes de símbolos geralmente são chamados de identificadores.  
  
 Símbolos fornecem uma maneira descritiva de fazer referência a recursos e objetos de interface do usuário, no seu código-fonte e enquanto estiver trabalhando com eles nos editores de recursos. Você pode exibir e manipular símbolos em um local conveniente usando o [caixa de diálogo símbolos de recurso](../windows/viewing-resource-symbols.md).  
  
 Quando você cria um novo recurso ou o objeto de recurso, o [editores de recursos](../windows/resource-editors.md) fornecer um nome padrão para o recurso, por exemplo, `IDC_RADIO1`e atribuir um valor a ela. A definição do valor de mais name é armazenada no arquivo Resource.h.  
  
> [!NOTE]
>  Quando você estiver copiando recursos ou objetos de recurso de um arquivo. RC para outro, Visual C++ pode alterar o recurso transferido símbolo valor, ou nome de símbolo e, para evitar conflitos com nomes de símbolos ou valores no arquivo existente.  
  
 À medida que seu aplicativo aumenta de tamanho e sofisticação, aumenta o número de recursos e símbolos. Grandes números de símbolos espalhados por vários arquivos de rastreamento pode ser difícil. O [caixa de diálogo símbolos de recurso](../windows/resource-symbols-dialog-box.md) simplifica o gerenciamento de símbolo, oferecendo uma ferramenta central por meio do qual você pode:  
  
- [Símbolos de recurso de exibição](../windows/viewing-resource-symbols.md)  
  
- [Criar novos símbolos](../windows/creating-new-symbols.md)  
  
- [Alterar símbolos não atribuídos](../windows/changing-unassigned-symbols.md)  
  
- [Excluir os símbolos não atribuídos](../windows/deleting-unassigned-symbols.md)  
  
- [Abra o Editor de recurso para um determinado símbolo](../windows/opening-the-resource-editor-for-a-given-symbol.md)  
  
- [Alterar um símbolo ou um nome de símbolo (ID)](../windows/changing-a-symbol-or-symbol-name-id.md)  
  
- [Altere o valor numérico do símbolo](../windows/changing-a-symbol-s-numeric-value.md)  
  
- [Alterar os nomes dos arquivos de cabeçalho de símbolo](../windows/changing-the-names-of-symbol-header-files.md)  
  
- [Incluir compartilhados (somente leitura) ou calculados símbolos](../windows/including-shared-read-only-or-calculated-symbols.md)  
  
- [Exibir IDs de símbolo predefinido](../windows/predefined-symbol-ids.md)  
  
 Para obter informações sobre como adicionar recursos a projetos gerenciados, consulte [recursos em aplicativos de área de trabalho](/dotnet/framework/resources/index) no *guia do desenvolvedor do .NET Framework.* Para obter informações sobre como adicionar manualmente os arquivos de recurso para projetos gerenciados, acessar recursos, exibir recursos estáticos e atribuir cadeias de caracteres de recurso para propriedades, consulte [criando arquivos de recursos para aplicativos de área de trabalho](/dotnet/framework/resources/creating-resource-files-for-desktop-apps). Para obter informações sobre globalização e localização de recursos em aplicativos gerenciados, consulte [Globalizing e localização de aplicativos do .NET Framework](/dotnet/standard/globalization-localization/index).  
  
## <a name="requirements"></a>Requisitos  
 Win32  
  
## <a name="see-also"></a>Consulte também  
 [Como: Procurar símbolos em recursos](../windows/how-to-search-for-symbols-in-resources.md)   
 [Editores de recursos](../windows/resource-editors.md)   
 [Arquivos de recurso](../windows/resource-files-visual-studio.md)

