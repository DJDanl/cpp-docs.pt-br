---
title: Editor de informações de versão | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: conceptual
f1_keywords:
- vc.editors.version.F1
dev_langs:
- C++
helpviewer_keywords:
- Version Information editor, about Version Information editor
- editors, Version Information
- resource editors, Version Information editor
ms.assetid: 772e6f19-f765-4cec-9521-0ad3eeb99f9b
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 76a76dbb3d8b41c2366f354f9c3c8d66ccc3743f
ms.sourcegitcommit: d55ac596ba8f908f5d91d228dc070dad31cb8360
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/08/2018
---
# <a name="version-information-editor"></a>Editor de informações da versão
Informações de versão consistem da empresa e identificação de produto, um número de versão do produto e a notificação de direitos autorais e marcas. Com o editor de informações de versão, você pode cria e manter esses dados, que são armazenados no recurso de informações de versão. O recurso de informações de versão não é necessário por um aplicativo, mas é um local útil para coletar informações que identificam o aplicativo. Informações de versão também são usadas por APIs de instalação.  
  
 Um recurso de informações de versão tem um bloco superior e um ou mais blocos inferiores: um único bloco de informações fixa na parte superior e um ou mais blocos de informações de versão na parte inferior (para outros idiomas e/ou conjuntos de caracteres). O bloco superior tem caixas numéricas editáveis e selecionável nas listas suspensas. Os blocos inferiores tem apenas as caixas de texto editável.  
  
> [!NOTE]
>  O padrão do Windows é ter apenas uma versão recurso, denominado VS_VERSION_INFO.  
  
 O editor de informações de versão permite que você:  
  
-   [Editar uma cadeia de caracteres em um recurso de informações de versão](../windows/editing-a-string-in-a-version-information-resource.md)  
  
-   [Adicionar informações de versão para outro idioma (novo bloco de informações de versão)](../windows/adding-version-information-for-another-language.md)  
  
-   [Excluir um bloco de informações de versão](../windows/deleting-a-version-information-block.md)  
  
-   [Acessar informações de versão no seu programa](../windows/accessing-version-information-from-within-your-program.md)  
  
    > [!NOTE]
    >  Ao usar o editor de informações de versão, em muitas instâncias clique para exibir um menu de atalho de comandos específicos do recurso. Por exemplo, se você clicar em ao apontando para uma entrada de cabeçalho do bloco, o menu de atalho mostra os comandos a nova versão de informações de bloco e excluir informações de versão do bloco.  
  
 Para obter informações sobre como adicionar recursos a projetos gerenciados, consulte [recursos em aplicativos de área de trabalho](/dotnet/framework/resources/index) no *guia do desenvolvedor do .NET Framework.* Para obter informações sobre como adicionar manualmente os arquivos de recurso para projetos gerenciados, acessar recursos, exibir recursos estáticos e atribuir cadeias de caracteres de recurso para propriedades, consulte [criando arquivos de recursos para aplicativos de área de trabalho](/dotnet/framework/resources/creating-resource-files-for-desktop-apps). Para obter informações sobre globalização e localização de recursos em aplicativos gerenciados, consulte [Globalizing e localização de aplicativos do .NET Framework](/dotnet/standard/globalization-localization/index).  
  
## <a name="requirements"></a>Requisitos  
 Win32  
  
## <a name="see-also"></a>Consulte também  
 [Editores de recursos](../windows/resource-editors.md)   
 [Menus e outros recursos](http://msdn.microsoft.com/library/windows/desktop/ms632583.aspx)

