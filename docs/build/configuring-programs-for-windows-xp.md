---
title: "Configurando programas C++ 11 para Windows XP | Microsoft Docs"
ms.custom: ""
ms.date: "12/16/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
dev_langs: 
  - "C++"
ms.assetid: 1e4487b3-d815-4123-878b-5718b22f0fd5
caps.latest.revision: 14
caps.handback.revision: 11
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Configurando programas C++ 11 para Windows XP
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Como [!INCLUDE[vsprvs](../assembler/masm/includes/vsprvs_md.md)] oferece suporte a vários conjuntos de ferramentas de plataforma, é possível direcionar para sistemas operacionais e as bibliotecas de tempo de execução que não há suporte para o conjunto de ferramentas padrão.  Por exemplo, você pode usar os aprimoramentos de linguagem 11 C \+ \+, compiladores, bibliotecas e outros recursos implementados em [!INCLUDE[vsprvs](../assembler/masm/includes/vsprvs_md.md)] para criar aplicativos destinados [!INCLUDE[winxp](../build/includes/winxp_md.md)] e [!INCLUDE[WinXPSvr](../build/includes/winxpsvr_md.md)].  Você pode usar conjuntos de ferramentas de plataforma mais antigos para manter o código herdado compatíveis com o binário e ainda aproveitar os novos recursos do [!INCLUDE[vsprvs](../assembler/masm/includes/vsprvs_md.md)] IDE.  
  
> [!NOTE]
>  Você deve instalar [!INCLUDE[vs_dev11_long](../build/includes/vs_dev11_long_md.md)] atualização 4 para adicionar suporte para conjunto de ferramentas de plataforma [!INCLUDE[winxp](../build/includes/winxp_md.md)] e [!INCLUDE[WinXPSvr](../build/includes/winxpsvr_md.md)] para [!INCLUDE[vs_dev11_long](../build/includes/vs_dev11_long_md.md)].  Para baixar e instalar uma cópia do [!INCLUDE[vs_dev11_long](../build/includes/vs_dev11_long_md.md)] atualização 4, consulte [Microsoft Visual Studio Express 2012 para Windows Desktop](http://go.microsoft.com/fwlink/?LinkID=265464) no Microsoft Download Center.  Instale o [atualização 4 do Visual Studio 2012](http://go.microsoft.com/fwlink/?LinkID=335900) para obter o conjunto de ferramentas de plataforma v110\_xp.  Use o Windows Update para receber as últimas atualizações de software após a instalação.  
  
## Direcionamento de experiência do Windows XP  
 As ferramentas da plataforma Windows XP que está incluída no [!INCLUDE[vsprvs](../assembler/masm/includes/vsprvs_md.md)] é uma versão do [!INCLUDE[win7](../build/includes/win7_md.md)] SDK que foi incluído no [!INCLUDE[vs_dev10_long](../build/includes/vs_dev10_long_md.md)], mas usa o compilador C\+\+ atual.  Ele também configura as propriedades do projeto para valores padrão apropriados — por exemplo, a especificação de um vinculador compatível para o direcionamento de nível inferior.  Somente os aplicativos da área de trabalho Windows que são criados usando as ferramentas da plataforma Windows XP executados em [!INCLUDE[winxp](../build/includes/winxp_md.md)] e [!INCLUDE[WinXPSvr](../build/includes/winxpsvr_md.md)], mas esses aplicativos também podem ser executados em sistemas operacionais mais recentes — por exemplo, o Windows Vista, [!INCLUDE[win7](../build/includes/win7_md.md)], [!INCLUDE[winsvr08](../build/includes/winsvr08_md.md)], [!INCLUDE[win8](../build/includes/win8_md.md)], ou [!INCLUDE[winserver8](../build/includes/winserver8_md.md)].  
  
#### Para direcionar o Windows XP  
  
1.  Em **Solution Explorer**, abra o menu de atalho para o seu projeto e escolha **propriedades**.  
  
2.  No **Property Pages** caixa de diálogo para o projeto, em **Propriedades de configuração**, **geral**, defina o **Ferramentas da plataforma** propriedade para o conjunto de ferramentas do Windows XP desejado.  Por exemplo, escolher **Visual Studio 2012 – Windows XP \(v110\_xp\)** criar código que é binário compatível com as Microsoft Visual C\+\+ 2012 redistribuível bibliotecas.  
  
### Suporte de tempo de execução C\+\+  
 Juntamente com as ferramentas da plataforma Windows XP, a biblioteca C Runtime \(CRT\), modelo Biblioteca STL \(Standard\), biblioteca ATL \(Active Template\), biblioteca de tempo de execução de simultaneidade \(ConCRT\), biblioteca de padrões paralelos \(PPL\), Microsoft Foundation Class Library \(MFC\) e biblioteca C\+\+ AMP \(C\+\+ Accelerated maciça de programação\) incluem suporte de tempo de execução para [!INCLUDE[winxp](../build/includes/winxp_md.md)] e [!INCLUDE[WinXPSvr](../build/includes/winxpsvr_md.md)].  Para esses sistemas operacionais, as versões com suporte são [!INCLUDE[winxp](../build/includes/winxp_md.md)] Service Pack 3 \(SP3\) para x86, [!INCLUDE[winxp](../build/includes/winxp_md.md)] Service Pack 2 \(SP2\) para x64, e [!INCLUDE[WinXPSvr](../build/includes/winxpsvr_md.md)] Service Pack 2 \(SP2\) para x86 e x64.  
  
 Essas bibliotecas são compatíveis com os conjuntos de ferramentas de plataforma instalados por[!INCLUDE[vsprvs](../assembler/masm/includes/vsprvs_md.md)], dependendo do destino:  
  
|Biblioteca|Padrão plataforma toolset direcionamento Windows aplicativos de desktop|Padrão de direcionamento do conjunto de ferramentas de plataforma [!INCLUDE[win8_appname_long](../build/includes/win8_appname_long_md.md)] aplicativos|Direcionamento de conjunto de ferramentas de plataforma do Windows XP [!INCLUDE[winxp](../build/includes/winxp_md.md)], [!INCLUDE[WinXPSvr](../build/includes/winxpsvr_md.md)]|  
|----------------|-----------------------------------------------------------------------------|-----------------------------------------------------------------------------------------------------------------------------------------------------|-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|  
|CRT|X|X|X|  
|STL|X|X|X|  
|ATL|X|X|X|  
|ConCRT\/PPL|X|X|X|  
|MFC|X||X|  
|C\+\+ AMP|X|X||  
  
> [!NOTE]
>  Aplicativos escritos em C\+\+ \/CLI CLI e o destino do .NET Framework 4 executados em [!INCLUDE[winxp](../build/includes/winxp_md.md)] e [!INCLUDE[WinXPSvr](../build/includes/winxpsvr_md.md)].  
  
### Diferenças entre os conjuntos de ferramentas  
 Devido às diferenças de suporte de plataforma e de biblioteca, a experiência de desenvolvimento para aplicativos que usam um conjunto de ferramentas de plataforma do Windows XP não é tão completa para aplicativos que usam o padrão [!INCLUDE[vsprvs](../assembler/masm/includes/vsprvs_md.md)] Ferramentas da plataforma.  
  
-   **Recursos da linguagem C\+\+**  
  
     Somente C \+ \+ 11 recursos de linguagem implementado em [!INCLUDE[vs_dev11_long](../build/includes/vs_dev11_long_md.md)] têm suporte em aplicativos que usam o conjunto de ferramentas de plataforma v110\_xp.  Somente os recursos do C\+\+ 11 implementados no [!INCLUDE[vs_dev12](../atl-mfc-shared/includes/vs_dev12_md.md)] são suportados em aplicativos que usam o conjunto de ferramentas de plataforma v120\_xp.  [!INCLUDE[vsprvs](../assembler/masm/includes/vsprvs_md.md)] usa o compilador correspondente quando ele cria usando os conjuntos de ferramentas de plataforma mais antigos.  Use um conjunto de ferramentas de plataforma mais recente do Windows XP para tirar proveito de recursos adicionais do C \+ \+ 11 implementado nessa versão.  
  
-   **Depuração remota**  
  
     Ferramentas remotas para [!INCLUDE[vsprvs](../assembler/masm/includes/vsprvs_md.md)] não oferece suporte a depuração remota em [!INCLUDE[winxp](../build/includes/winxp_md.md)] ou [!INCLUDE[WinXPSvr](../build/includes/winxpsvr_md.md)].  Para depurar um aplicativo quando ele é executado em [!INCLUDE[winxp](../build/includes/winxp_md.md)] ou [!INCLUDE[WinXPSvr](../build/includes/winxpsvr_md.md)], você pode usar um depurador de uma versão mais antiga do [!INCLUDE[vsprvs](../assembler/masm/includes/vsprvs_md.md)] para depurá\-los localmente ou remotamente.  Isso é semelhante a experiência de depuração de um aplicativo no Windows Vista, que é um destino de tempo de execução do conjunto de ferramentas de plataforma, mas não é um destino de depuração remoto.  
  
-   **Análise estática**  
  
     Os conjuntos de ferramentas de plataforma do Windows XP não oferecem suporte a análise estática porque as anotações de SAL para o [!INCLUDE[win7](../build/includes/win7_md.md)] SDK e as bibliotecas de tempo de execução são incompatíveis.  Quando você deseja executar uma análise estática em um aplicativo que oferece suporte a [!INCLUDE[winxp](../build/includes/winxp_md.md)] ou [!INCLUDE[WinXPSvr](../build/includes/winxpsvr_md.md)], você pode alternar temporariamente a solução para o conjunto de ferramentas de plataforma padrão para realizar a análise de destino e, em seguida, alternar de volta para o conjunto de ferramentas da plataforma Windows XP para criar o aplicativo.  
  
-   **Depuração de gráficos do DirectX**  
  
     Porque o depurador de gráficos não dá suporte a API do Direct3D 9, não pode ser usado para depurar aplicativos que usam o Direct3D [!INCLUDE[winxp](../build/includes/winxp_md.md)] ou [!INCLUDE[WinXPSvr](../build/includes/winxpsvr_md.md)].  No entanto, se o aplicativo implementar um renderizador alternativo que usa o Direct3D 10 ou APIs do Direct3D 11, o depurador de gráficos pode ser usado para diagnosticar problemas com o uso dessas APIs.  
  
-   **Criando HLSL**  
  
     Por padrão, o conjunto de ferramentas do Windows XP não compila os arquivos de origem do código HLSL.  Para compilar arquivos HLSL, baixe e instale a junho de 2010 SDK do DirectX e defina o projeto do VC diretórios para incluí\-lo.  Para obter mais informações, consulte o "SDK do DirectX não registra os caminhos de inclusão\/biblioteca com o Visual Studio 2010" seção o [junho de 2010 página de download do SDK do DirectX](http://www.microsoft.com/download/details.aspx?displaylang=en&id=6812).