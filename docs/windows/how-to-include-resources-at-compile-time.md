---
title: 'Como: incluir recursos em tempo de compilação | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: conceptual
f1_keywords:
- vs.resvw.resource.including
- vc.resvw.resource.including
dev_langs:
- C++
helpviewer_keywords:
- compiling source code, including resources
- comments [C++], compiled files
- resources [Visual Studio], including at compile time
- projects [C++], including resources
- '#include directive'
- include directive (#include)
ms.assetid: 357e93c2-0a29-42f9-806f-882f688b8924
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 765d78ef5371015fdce3e505e7a2454c29c6c97e
ms.sourcegitcommit: d55ac596ba8f908f5d91d228dc070dad31cb8360
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/08/2018
ms.locfileid: "33880144"
---
# <a name="how-to-include-resources-at-compile-time"></a>Como incluir recursos na hora da compilação
Normalmente, é fácil e conveniente para trabalhar com a organização padrão de todos os recursos em um arquivo de script (. rc) do recurso. No entanto, você pode adicionar recursos em outros arquivos para o projeto atual no tempo de compilação listando-os no **diretivas de tempo de compilação** caixa o [caixa de diálogo recurso inclui](../windows/resource-includes-dialog-box.md).  
  
 Há várias razões para colocar recursos em um arquivo que não seja o arquivo. rc principal:  
  
-   Para adicionar comentários a instruções de recurso que não serão excluídas quando você salvar o arquivo. rc.  
  
     Os editores de recursos não leia arquivos. rc ou resource.h diretamente. O compilador de recurso compila em arquivos de .aps, que são consumidos por editores de recursos. Esse arquivo é uma etapa de compilação e armazena apenas dados simbólicos. Como o processo de compilação com um normal, as informações que não seja simbólicas (por exemplo, comentários) são descartadas durante o processo de compilação. Sempre que o arquivo .aps fica fora de sincronia com o arquivo. RC, o arquivo. RC é gerada novamente (por exemplo, quando você salva, o editor de recurso substitui o arquivo. RC e o arquivo resource.h). As alterações aos recursos próprios permanecerá incorporadas no arquivo. RC, mas comentários sempre será perdidos quando o arquivo. RC é substituído.  
  
-   Para incluir recursos que já foram desenvolvidos e testados e não precisa de modificação adicional. (Todos os arquivos que são incluídos, mas não tem uma extensão. rc não serão editáveis por editores de recursos.)  
  
-   Para incluir recursos que estão sendo usados por vários projetos diferentes, ou que fazem parte de um sistema de controle de versão do código fonte e, portanto, deve existir em um local central onde modificações afetará todos os projetos.  
  
-   Para incluir recursos (como recursos RCDATA) que estão em um formato personalizado. Recursos RCDATA podem ter requisitos especiais. Por exemplo, você não pode usar uma expressão como um valor para o campo nameID. Consulte o [!INCLUDE[winsdkshort](../atl-mfc-shared/reference/includes/winsdkshort_md.md)] documentação para obter mais informações.  
  
 Se você tiver seções em seus arquivos. rc existentes que atendem a qualquer uma dessas condições, você deve colocar as seções em um ou mais arquivos. rc separam e incluem-los em seu projeto usando o [caixa de diálogo recurso inclui](../windows/resource-includes-dialog-box.md). O *Projectname*. RC2 arquivo criado no subdiretório \res de um novo projeto é usado para essa finalidade.  
  
### <a name="to-include-resources-in-your-project-at-compile-time"></a>Para incluir recursos em seu projeto no tempo de compilação  
  
1.  Coloque os recursos em um arquivo de script de recurso com um nome de arquivo exclusivo. Não use *projectname*. RC, porque esse é o nome de arquivo usado para o arquivo de script de recurso principal.  
  
2.  Clique com botão direito no arquivo. RC (em [exibição recursos](../windows/resource-view-window.md)) e escolha **inclui recursos** no menu de atalho.  
  
3.  No **diretivas de tempo de compilação** caixa, adicione o [#include](../preprocessor/hash-include-directive-c-cpp.md) diretiva de compilador para incluir o novo arquivo de recurso no arquivo de recurso principal no ambiente de desenvolvimento.  
  
     Os recursos nos arquivos incluídos dessa maneira são feitos uma parte do seu arquivo executável em tempo de compilação. Eles não estão diretamente disponíveis para edição ou modificação quando você estiver trabalhando no arquivo de RC principal do seu projeto. Você precisa abrir arquivos. rc incluído separadamente. Todos os arquivos que são incluídos, mas não tem uma extensão. rc não serão editáveis por editores de recursos.  
  

  
 Requisitos  
  
 Win32  
  
## <a name="see-also"></a>Consulte também  
 [Arquivos de recurso](../windows/resource-files-visual-studio.md)   
 [Editores de recursos](../windows/resource-editors.md)