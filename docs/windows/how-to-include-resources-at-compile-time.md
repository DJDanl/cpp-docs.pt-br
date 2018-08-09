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
ms.openlocfilehash: 28374482abd5d2e039c92adbd34f261bdc259b9d
ms.sourcegitcommit: 38af5a1bf35249f0a51e3aafc6e4077859c8f0d9
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/09/2018
ms.locfileid: "40018910"
---
# <a name="how-to-include-resources-at-compile-time"></a>Como incluir recursos na hora da compilação
Normalmente, é fácil e conveniente para trabalhar com a organização padrão de todos os recursos em um arquivo de script (. rc) do recurso. No entanto, você pode adicionar recursos em outros arquivos ao seu projeto atual em tempo de compilação listando-os na **diretivas de tempo de compilação** caixa de [caixa de diálogo recurso inclui](../windows/resource-includes-dialog-box.md).  
  
 Há várias razões para colocar recursos em um arquivo que não seja o arquivo. rc principal:  
  
-   Para adicionar comentários a instruções de recursos que não são excluídas quando você salvar o arquivo. rc.  
  
     Os editores de recursos não ler diretamente. rc ou `resource.h` arquivos. O compilador de recurso compila-os em arquivos de .aps, que são consumidos pelos editores de recursos. Esse arquivo é uma etapa de compilação e armazena apenas dados simbólicos. Como com um normal de processo de compilação, as informações que não seja simbólicas (por exemplo, comentários) são descartadas durante o processo de compilação. Sempre que o arquivo .aps obtém fora de sincronia com o arquivo. RC, o arquivo. rc for gerado novamente (por exemplo, quando você salva, o editor de recurso substitui o arquivo. RC e o `resource.h` arquivo). Todas as alterações para os próprios recursos permanecerão incorporadas no arquivo. RC, mas comentários sempre serão perdidos depois que o arquivo. RC é substituído.  
  
-   Para incluir recursos que já foram desenvolvidos e testados e não precisa de modificação adicional. (Todos os arquivos que são incluídos, mas não tem uma extensão. rc não será editáveis pelos editores de recursos.)  
  
-   Para incluir recursos que estão sendo usados por vários projetos diferentes ou que fazem parte de um sistema de controle de versão do código-fonte e, portanto, deve existir em um local central onde as modificações afetará todos os projetos.  
  
-   Para incluir recursos (como recursos RCDATA) que estão em um formato personalizado. Recursos RCDATA podem ter requisitos especiais. Por exemplo, você não pode usar uma expressão como um valor para o campo de nameID. Consulte o [!INCLUDE[winsdkshort](../atl-mfc-shared/reference/includes/winsdkshort_md.md)] documentação para obter mais informações.  
  
 Se você tiver seções em seus arquivos. rc existentes que atendem a qualquer uma dessas condições, você deve colocar as seções em um ou mais arquivos. rc separam e incluem-los no seu projeto usando o [caixa de diálogo recurso inclui](../windows/resource-includes-dialog-box.md). O *Projectname*arquivo .rc2 criado no subdiretório \res de um novo projeto é usado para essa finalidade.  
  
### <a name="to-include-resources-in-your-project-at-compile-time"></a>Para incluir recursos em seu projeto em tempo de compilação  
  
1.  Coloque os recursos em um arquivo de script de recurso com um nome de arquivo exclusivo. Não use *projectname*. RC, porque esse é o nome de arquivo usado para o arquivo de script de recurso principal.  
  
2.  Clique com botão direito no arquivo. RC (no [exibição de recurso](../windows/resource-view-window.md)) e escolha **recurso inclui** no menu de atalho.  
  
3.  No **diretivas de tempo de compilação** caixa, adicione o [#include](../preprocessor/hash-include-directive-c-cpp.md) diretiva do compilador para incluir o novo arquivo de recurso no arquivo de recurso principal no ambiente de desenvolvimento.  
  
     Os recursos em arquivos incluídos dessa maneira são feitos uma parte do seu arquivo executável no tempo de compilação. Eles não estão diretamente disponíveis para edição ou modificação quando você estiver trabalhando no arquivo. rc principal do seu projeto. Você precisa abrir arquivos. rc incluído separadamente. Todos os arquivos que são incluídos, mas não tem uma extensão. rc não será editáveis pelos editores de recursos.  
  
## <a name="requirements"></a>Requisitos  
 Win32  
  
## <a name="see-also"></a>Consulte também  
 [Arquivos de recurso](../windows/resource-files-visual-studio.md)   
 [Editores de recursos](../windows/resource-editors.md)