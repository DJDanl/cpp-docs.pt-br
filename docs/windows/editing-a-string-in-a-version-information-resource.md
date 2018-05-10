---
title: Edição de uma cadeia de caracteres em um recurso de informações de versão | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: conceptual
f1_keywords:
- vc.editors.version
dev_langs:
- C++
helpviewer_keywords:
- version information resources
- resources [Visual Studio], editing version information
ms.assetid: d3a7d4e4-7d31-47c2-902c-f50b8404ba4f
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 80795f912ab41809b19e77bd33f56243541d4de1
ms.sourcegitcommit: d55ac596ba8f908f5d91d228dc070dad31cb8360
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/08/2018
---
# <a name="editing-a-string-in-a-version-information-resource"></a>Editando uma cadeia de caracteres em um recurso de informações da versão
### <a name="to-edit-a-string-in-a-version-information-resource"></a>Para editar uma cadeia de caracteres em um recurso de informações de versão  
  
1.  Clique no item uma vez para selecioná-lo, em seguida, para começar a editá-lo. Faça as alterações diretamente na tabela de informações de versão ou no [janela propriedades](/visualstudio/ide/reference/properties-window). As alterações feitas serão refletidas em ambos os locais.  
  
     **Observação** ao editar o **FILEFLAGS** chave no editor de informações de versão, você observará que não é possível definir o **depurar**, **compilação particular**, ou **Compilação especial** propriedades (na janela Propriedades) para arquivos. RC:  
  
    -   Define as informações de versão de **depurar** propriedade com um #ifdef no script de recurso, com base no **Debug** sinalizador de compilação.  
  
    -   Se o **compilação particular** chave tem um **valor** definido na tabela de informações de versão, correspondente **compilação particular** propriedade (na janela Propriedades) para o **FILEFLAGS** chave será **True**. Se o **valor** está vazia, a propriedade será **False**. Da mesma forma, o **compilação especial** chave (na tabela de informações de versão) está ligado ao **compilação especial** propriedade para o **FILEFLAGS** chave.  
  
 Você pode classificar a sequência de informações do bloco de cadeia de caracteres clicando nos títulos de coluna de valor ou a chave. Esses cabeçalhos reorganizar automaticamente as informações para a sequência selecionada.  
  
 Para obter informações sobre como adicionar recursos a projetos gerenciados, consulte [recursos em aplicativos de área de trabalho](/dotnet/framework/resources/index) no *guia do desenvolvedor do .NET Framework.* Para obter informações sobre como adicionar manualmente os arquivos de recurso para projetos gerenciados, acessar recursos, exibir recursos estáticos e atribuir cadeias de caracteres de recurso para propriedades, consulte [criando arquivos de recursos para aplicativos de área de trabalho](/dotnet/framework/resources/creating-resource-files-for-desktop-apps). Para obter informações sobre globalização e localização de recursos em aplicativos gerenciados, consulte [Globalizing e localização de aplicativos do .NET Framework](/dotnet/standard/globalization-localization/index).  
  
 **Requisitos**  
  
 Win32  
  
## <a name="see-also"></a>Consulte também  
 [Editor de informações de versão](../windows/version-information-editor.md)   
 [Informações de versão (Windows)](https://msdn.microsoft.com/library/windows/desktop/ms646981.aspx)

