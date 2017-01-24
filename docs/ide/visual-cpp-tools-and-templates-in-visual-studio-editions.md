---
title: "Ferramentas e modelos do Visual C++ em edi&#231;&#245;es do Visual Studio | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "edições [C++]"
  - "versões [C++]"
  - "Visual C++, versões"
ms.assetid: 3d88607b-9cc4-490a-8d4c-31ee7610a26f
caps.latest.revision: 51
caps.handback.revision: 51
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Ferramentas e modelos do Visual C++ em edi&#231;&#245;es do Visual Studio
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

As tabelas a seguir mostram os recursos do Visual C\+\+ que estão disponíveis no Visual Studio.  Um X em uma célula indica que o recurso está disponível. uma célula vazia indica que o recurso não está disponível.  Notas de parênteses indicam que um recurso está disponível, mas restrito.  
  
## Plataformas  
  
||||||  
|-|-|-|-|-|  
|Plataforma|Visual Studio Express para Windows 10|Visual Studio Express para Windows Desktop|Comunidade do Visual Studio\/Professional|O Visual Studio Enterprise|  
|Área de Trabalho do Windows||X|X|X|  
|Plataforma Windows universal \(\(telefone, tablet, PC, Xbox, IoT e HoloLens\)\)|X||X|X|  
|Windows Store 8.1|||X|X|  
|Windows Phone 8.0|||X|X|  
|Android|||X|X|  
|iOS|||X|X|  
  
## Compiladores  
  
|Compilador|Visual Studio Express para Windows|Visual Studio Express para Windows Desktop|Visual Studio Professional \/ comunidade|O Visual Studio Enterprise|  
|----------------|----------------------------------------|------------------------------------------------|----------------------------------------------|--------------------------------|  
|compilador x86 de 32 bit|X|X|X|X|  
|Compilador cruzado X86\_arm|X||X|X|  
|64 bits [!INCLUDE[vcprx64](../Token/vcprx64_md.md)] compilador|||X|X|  
|X86\_ [!INCLUDE[vcprx64](../Token/vcprx64_md.md)] compilador cruzado|X|X|X|X|  
  
## Cabeçalhos e bibliotecas  
  
|Biblioteca ou cabeçalho|Visual Studio Express para Windows|Visual Studio Express para Windows Desktop|Visual Studio Professional \/ comunidade|O Visual Studio Enterprise|  
|-----------------------------|----------------------------------------|------------------------------------------------|----------------------------------------------|--------------------------------|  
|Cabeçalhos do Windows e bibliotecas e bibliotecas CRT|\(X\)|X|X|X|  
|STL|X|X|X|X|  
|ATL|||X|X|  
|MFC|||X|X|  
|Biblioteca de classes .NET Framework||X|X|X|  
|Biblioteca de suporte C\+\+ para .NET||X|X|X|  
|OpenMP|X|X|X|X|  
  
## Modelos de projeto  
  
|Layout|Visual Studio Express para Windows|Visual Studio Express para Windows Desktop|Visual Studio Professional \/ comunidade|O Visual Studio Enterprise|  
|------------|----------------------------------------|------------------------------------------------|----------------------------------------------|--------------------------------|  
|Modelos XAML para UWP, Windows 8.1, Windows Phone 8.0|X||X|X|  
|Aplicativo Direct3D|X||X|X|  
|DLL \(aplicativos da Windows Store\)|X||X|X|  
|Biblioteca Estática \(aplicativos da Windows Store\)|X||X|X|  
|Componente do Tempo de Execução do Windows|X||X|X|  
|Biblioteca de Teste de Unidade \(aplicativos da Windows Store\)|X||X|X|  
|Projeto do ATL|||X|X|  
|Biblioteca de classes \(CLR\)||X|X|X|  
|Aplicativo do Console CLR||X|X|X|  
|Projeto CLR Vazio||X|X|X|  
|Assistente de Personalização|||X|X|  
|Projeto Vazio||X|X|X|  
|Projeto Makefile||X|X|X|  
|Controle ActiveX do MFC|||X|X|  
|Aplicativo do MFC|||X|X|  
|DLL do MFC|||X|X|  
|Projeto de Teste|X|X|X|X|  
|Aplicativo do Console Win32||X|X|X|  
|Projeto Win32||X|X|X|  
  
## Ferramentas  
  
|Ferramenta|Visual Studio Express para Windows|Visual Studio Express para Windows Desktop|Visual Studio Professional \/ comunidade|O Visual Studio Enterprise|  
|----------------|----------------------------------------|------------------------------------------------|----------------------------------------------|--------------------------------|  
|Vinculador incremental \(Link.exe\)|X|X|X|X|  
|Utilitário de manutenção do programa \(Nmake.exe\)||X|X|X|  
|Gerador de lib \(Lib.exe\)|X|X|X|X|  
|Compilador de recursos do Windows \(Rc.exe\)|X|X|X|X|  
|Recurso do Windows para o conversor de objeto \(CvtRes.exe\)||X|X|X|  
|Procurar o utilitário de manutenção de informações \(BscMake.exe\)|X|X|X|X|  
|Nome do C\+\+ Undecorator \(Undname.exe\)|X|X|X|X|  
|Despejo COFF\/PE \(Dumpbin.exe\)|X|X|X|X|  
|Editor de COFF\/PE \(Editbin.exe\)|X|X|X|X|  
|MASM \(Ml.exe\)|||X|X|  
|Espionar\+\+|||X|X|  
|ErrLook|||X|X|  
|AtlTrace|||X|X|  
|Devenv.com|||X|X|  
|Regras de inferência|||X|X|  
|Atualizar VCBuild. vcproj projetos MSBuild \(VCUpgrade.exe\)|X|X|X|X|  
|Otimizações guiada por perfil|||X|X|  
  
## Recursos de depuração  
  
|Recurso de depuração|Visual Studio Express para Windows|Visual Studio Express para Windows Desktop|Visual Studio Professional \/ comunidade|O Visual Studio Enterprise|  
|--------------------------|----------------------------------------|------------------------------------------------|----------------------------------------------|--------------------------------|  
|Depuração Nativa|X|X|X|X|  
|natvis \(visualização do tipo nativo\)|X|X|X|X|  
|Depuração de gráficos|X||X|X|  
|Depuração gerenciada||X|X|X|  
|Uso GPU|X||X|X|  
|Uso de memória|X||X|X|  
|Depuração Remota|X|X|X|X|  
|Depuração de SQL|||X|X|  
|Análise de código estático|Limitado|Limitado|X|X|  
  
## Designers e editores  
  
|Designer ou Editor|Visual Studio Express para Windows|Visual Studio Express para Windows Desktop|Visual Studio Professional \/ comunidade|O Visual Studio Enterprise|  
|------------------------|----------------------------------------|------------------------------------------------|----------------------------------------------|--------------------------------|  
|XAML Designer|X||X|X|  
|Designer\/Editor de estilo CSS|X|X|X|X|  
|Editor da Designer de HTML|X|X|X|X|  
|Editor de XML|X|X|X|X|  
|Editor de código\-fonte|X|X|X|X|  
|Recursos de produtividade: Refatoração, IntelliSense, formatação de código C\+\+|X|X|X|X|  
|Designer de Formulários do Windows||X|X|X|  
|Designer de dados|||X|X|  
|Editor de recursos nativos \(arquivos. rc\)|||X|X|  
|Editores de Recursos|X|X|X|X|  
|Editor de modelos|X||X|X|  
|Designer de sombreador|X||X|X|  
  
## Recursos de dados  
  
|Recurso de dados|Visual Studio Express para Windows|Visual Studio Express para Windows Desktop|Visual Studio Professional \/ comunidade|Visual Studio Premium|O Visual Studio Enterprise|  
|----------------------|----------------------------------------|------------------------------------------------|----------------------------------------------|---------------------------|--------------------------------|  
|Designer de dados|||X|X|X|  
|Objetos de dados|||X|X|X|  
|Serviços da Web|||X|X|X|  
|Gerenciador de Servidores|||X|X|X|  
  
## Compilação e sistemas de projeto  
  
|Compilação ou um recurso do projeto|Visual Studio Express para Windows|Visual Studio Express para Windows Desktop|Visual Studio Professional \/ comunidade|O Visual Studio Enterprise|  
|-----------------------------------------|----------------------------------------|------------------------------------------------|----------------------------------------------|--------------------------------|  
|Compilações de linha de comando \(msbuild.exe\)|X|X|X|X|  
|Nativo multiplataforma||X|X|X|  
|Multiplataforma gerenciado||X|X|X|  
|Compilações paralelas|X|X|X|X|  
|Compilações Personalizadas|X|X|X|X|  
|Extensibilidade de páginas de propriedade|X|X|X|X|  
  
## Automação e extensibilidade  
  
|Automação e extensibilidade|Visual Studio Express para Windows|Visual Studio Express para Windows Desktop|Visual Studio Professional \/ comunidade|O Visual Studio Enterprise|  
|---------------------------------|----------------------------------------|------------------------------------------------|----------------------------------------------|--------------------------------|  
|Modelos de objeto de extensibilidade|||X|X|  
|Modelo de código|||X|X|  
|Modelo de Projeto|||X|X|  
|Modelo do Editor de recursos|||X|X|  
|Modelo de Assistente|||X|X|  
|Modelo de objeto do depurador|||X|X|  
  
## Ferramentas de gerenciamento do ciclo de vida de aplicativos  
  
||||||  
|-|-|-|-|-|  
|Ferramenta|Visual Studio Express para Windows|Visual Studio Express para Windows Desktop|Visual Studio Professional \/ comunidade|O Visual Studio Enterprise|  
|Testes de unidade \(nativo framework\)|X|X|X|X|  
|Testes de unidade \(estrutura gerenciada\)||X|X|X|  
|Cobertura de código||||X|  
|Testes manuais||||X|  
|Teste exploratório||||X|  
|Gerenciamento de casos de teste||||X|  
|Gráficos de dependência e mapa de código|||somente leitura|X|  
|Depuração do mapa de códigos||||X|  
  
## Consulte também  
 [Instalando o Visual Studio](../Topic/Installing%20Visual%20Studio%202015.md)   
 [O que há de novo no Visual Studio 2015](../Topic/What's%20New%20in%20Visual%20Studio%202015.md)   
 [Tipos de projeto do Visual C\+\+](../ide/visual-cpp-project-types.md)   
 [Visual Database Tools edições](http://msdn.microsoft.com/pt-br/a7689adc-f16b-4cc7-b6fe-39ca0c711161)