---
title: "P&#225;ginas de propriedade do vinculador | Microsoft Docs"
ms.custom: ""
ms.date: "12/15/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
f1_keywords: 
  - "VC.Project.VCLinkerTool.RegisterOutput"
  - "VC.Project.VCLinkerTool.IgnoreImportLibrary"
  - "VC.Project.VCLinkerTool.UseLibraryDependencyInputs"
  - "VC.Project.VCLinkerTool.LinkLibraryDependencies"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Páginas de propriedade do vinculador"
  - "redirecionamento por usuário"
ms.assetid: 7e7671e5-a35a-4e67-9bdb-661d75c4d11e
caps.latest.revision: 13
caps.handback.revision: 13
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# P&#225;ginas de propriedade do vinculador
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Este tópico discute as seguintes propriedades na página de propriedades do vinculador de **Geral** :  
  
 **Ignorar Biblioteca de Importações**  
 Com o vinculador para não tentar vincular todas as saídas de .lib geradas desta compilação em qualquer projeto dependente.  Isso permite que o sistema do projeto trata os arquivos .dll que não gerenciar um arquivo de .lib quando criados.  Se um projeto depende de outro projeto que gerencia uma DLL, o sistema de projeto automaticamente vinculará o arquivo de .lib gerado pelo projeto filho.  Isso não pode ser necessário pelos projetos que estão gerando DLL COM ou DLL de somente recursos; essas dlls não têm exportações significativo.  Se uma DLL não tem nenhuma exportação, o vinculador não irá gerar um arquivo de .lib.  Se nenhum arquivo de exportação .lib presente no disco, e o sistema de projeto com o vinculador para vincular com essa DLL \(falta de\), o link falhará.  
  
 Use **Ignorar Biblioteca de Importações** para resolver este problema.  Quando definida como `Yes`, o sistema do projeto irá ignorar a presença ou a ausência do arquivo de .lib e fará com qualquer projeto que depender deste projeto não vincular com o arquivo inexistente de .lib.  
  
 Para acessar essa propriedade via programação, consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCLinkerTool.IgnoreImportLibrary%2A>.  
  
 **Saída do registro**  
 Executar regsvr32.exe \/s $ \(TargetPath\), que é válido somente em projetos .dll.  Para projetos .exe, essa propriedade é ignorada.  Se você quiser registrar uma saída .exe, definir um evento de postbuild na configuração para fazer o registro personalizado que é necessário sempre registrados para arquivos .exe.  
  
 Para acessar essa propriedade via programação, consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCLinkerTool.RegisterOutput%2A>.  
  
 **redirecionamento pelo usuário**  
 O registro em [!INCLUDE[vsprvs](../assembler/masm/includes/vsprvs_md.md)] foi feito tradicional em HKEY\_CLASSES\_ROOT \(HKCR\).  Com [!INCLUDE[wiprlhext](../c-runtime-library/reference/includes/wiprlhext_md.md)], para acessar HKCR você deve executar [!INCLUDE[vsprvs](../assembler/masm/includes/vsprvs_md.md)] no modo alto.  Os desenvolvedores sempre não deseja executar no modo alto mas ainda devem trabalhar com o registro.  Redirecionamento por usuário permite que você registrar sem ter que executar nesse modo.  
  
 Redirecionamento pelo usuário forçará todas as grava a HKCR a ser redirecionado a HKEY\_CURRENT\_USER \(HKCU\).  Se o redirecionamento pelo usuário é desativada, pode causar [Erro PRJ0050 \(compilação de projeto\)](../error-messages/tool-errors/project-build-error-prj0050.md) quando o programa tenta escrever HKCR.  
  
 **Dependências de biblioteca de link**  
 Oferece a você a opção de vincular em arquivos de .lib que são gerados por projetos dependentes.  Normalmente, você desejará vincular no arquivo de .lib.  
  
 Você também pode especificar um arquivo de .obj fornecendo o nome de arquivo e o caminho relativo, por exemplo **..\\..\\MyLibProject\\MyObjFile.obj**.  Se o código\-fonte para os \#includes do arquivo de .obj um cabeçalho pré\-compilado, por exemplo, pch.h arquivo de pch.obj está localizado na mesma pasta que **MyObjFile.obj** e você deve também adicionar **pch.obj** como uma dependência adicional.  
  
 **Use entradas de dependência de biblioteca**  
 Em um grande projeto, quando um projeto dependente gerencia um arquivo de .lib, vincular incremental é desativado.  Se há vários projetos dependentes que gerenciar arquivos de .lib, compilar o aplicativo pode levar um longo tempo.  Quando essa propriedade é definida como `Yes`, o sistema do projeto contém os arquivos de .obj para .libs gerado por projetos dependentes, para ativar vincular incremental.  
  
 Para obter informações sobre como acessar a página de propriedades do vinculador de **Geral** , consulte [Como: Especificar propriedades de Projeto com páginas de propriedades](../Topic/How%20to:%20Specify%20Project%20Properties%20with%20Property%20Pages.md).  
  
## Consulte também  
 [VC\+\+ Directories, Projects and Solutions, Options Dialog Box](http://msdn.microsoft.com/pt-br/e027448b-c811-4c3d-8531-4325ad3f6e02)   
 [Páginas de propriedade](../ide/property-pages-visual-cpp.md)