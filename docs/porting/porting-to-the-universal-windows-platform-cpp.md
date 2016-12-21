---
title: "Portando para a Plataforma Universal do Windows (C++) | Microsoft Docs"
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
ms.assetid: f662d2e4-8940-418d-8109-cb76cb8f8569
caps.latest.revision: 14
caps.handback.revision: 14
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Portando para a Plataforma Universal do Windows (C++)
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Neste tópico, você pode encontrar informações sobre como portar código C\+\+ existente para a plataforma de aplicativo do Windows 10, a plataforma Windows Universal. O que significa o termo *universal* é que seu código pode ser executado em qualquer um dos dispositivos que executam o Windows 10, incluindo a área de trabalho, telefone, tablets e futuros dispositivos que executam o Windows 10. Com o Windows 8.1, você criou um aplicativo que o destino Windows 8.1 e Windows Phone 8.1 usando um recurso de sistema de projeto especial chamado um projeto compartilhado. Aplicativos universais do Windows não usa esse mecanismo, mas em vez disso, você usar um único XAML que funciona bem em qualquer dispositivo que executa o Windows 10 e um único projeto. Você pode usar recursos de layout dinâmico em XAML para permitir que a interface do usuário do aplicativo para se adaptar aos tamanhos de exibição diferentes.  
  
 A documentação do Centro de desenvolvimento do Windows contém um guia para portar aplicativos para a plataforma Windows Universal do Windows 8.1. Consulte [Mover de tempo de execução do Windows 8 para UWP](http://msdn.microsoft.com/library/windows/apps/dn954974.aspx). Embora o guia enfoca principalmente em código c\#, a maioria das diretrizes é aplicável ao C\+\+. Os procedimentos a seguir contêm informações mais detalhadas.  
  
 Este tópico contém os procedimentos a seguir para mover o código para o UWP.  
  
1.  [Portando um aplicativo da Windows Store 8.1 para o UWP](#BK_81StoreApp)  
  
2.  [Portabilidade de um componente de tempo de execução do Windows 8.1 para o UWP](#BK_81Component)  
  
 Se você tiver uma DLL Win32 da área de trabalho clássica e desejar chamá\-la em um aplicativo de UWP, você pode fazer isso também. Usando esses procedimentos, você pode criar uma camada de interface do usuário UWP para um desktop Windows clássico aplicativo C\+\+ existente ou seu código C\+\+ padrão de plataforma cruzada. Consulte [Como usar o código C\+\+ existente em um aplicativo da Plataforma Universal do Windows](../Topic/How%20to:%20Use%20Existing%20C++%20Code%20in%20a%20Universal%20Windows%20Platform%20App.md).  
  
##  <a name="BK_81StoreApp"></a> Portando um aplicativo da Windows Store 8.1 para o UWP  
 Se você tiver um aplicativo da Windows 8.1 Store, você pode usar este procedimento para fazê\-lo funcionar o UWP e qualquer dispositivo que executa o Windows 10.  É uma boa idéia criar primeiro o projeto com [!INCLUDE[vs_dev14](../mfc/includes/vs_dev14_md.md)] como um projeto Windows 8.1, primeiro eliminar quaisquer problemas que surgem das alterações no compilador e bibliotecas. Depois disso, há duas maneiras para converter isso em um projeto do Windows 10 UWP. A maneira mais fácil \(conforme explicado no procedimento a seguir\) é criar um projeto Universal do Windows e copie o código existente para ela. Se você estiver usando um projeto Universal para área de trabalho do Windows 8.1 e Windows 8.1 Phone, seu projeto será iniciado com dois layouts diferentes em XAML mas final com um único layout dinâmico que ajusta o tamanho de exibição. A segunda maneira de converter um projeto para o Windows 10 é editar o arquivo de projeto e o arquivo Package. appxmanifest. Esse método é explicado no [Migrar aplicativos para a UWP \(Plataforma Universal do Windows\)](../misc/migrate-apps-to-the-universal-windows-platform-uwp.md).  
  
#### A porta de um aplicativo da Windows 8.1 Store para o UWP  
  
1.  Se você ainda não fez isso, abra o projeto de aplicativo do Windows 8.1 no [!INCLUDE[vs_dev14](../mfc/includes/vs_dev14_md.md)], e siga as instruções para atualizar o arquivo de projeto.  
  
     Você precisa ter instalado as ferramentas do Windows 8.1 na instalação do Visual Studio. Se você não tiver essas ferramentas instaladas, inicie a instalação do Visual Studio na janela programas e recursos, escolha [!INCLUDE[vs_dev14](../mfc/includes/vs_dev14_md.md)], e na janela de instalação, escolha **modificar**. Localize ferramentas do Windows 8.1, verifique se que ele está selecionado e escolha OK.  
  
2.  Abra a janela de propriedades do projeto e em C\+\+, geral, defina o conjunto de ferramentas de plataforma como v140, as ferramentas de compilação para [!INCLUDE[vs_dev14](../mfc/includes/vs_dev14_md.md)].  
  
3.  Compilar o projeto como um projeto Windows 8.1 e resolva os erros de compilação. Erros neste estágio são provavelmente devido a alterações nas ferramentas de compilação e bibliotecas significativas. Consulte [Alterações significativas no Visual C\+\+ 2015](../Topic/Visual%20C++%20change%20history%202003%20-%2020151.md) para obter uma explicação detalhada das alterações que podem afetar seu código.  
  
     Depois que o projeto é compilado corretamente, você está pronto para a porta Universal do Windows \(Windows 10\).  
  
4.  Crie um novo projeto de aplicativo Universal do Windows usando o modelo em branco. Você talvez queira dar a ele o mesmo nome do seu projeto existente, embora para fazer que os projetos deve ser em diretórios diferentes.  
  
5.  Feche a solução e, em seguida, usando o Windows Explorer ou a linha de comando, copiem os arquivos de código \(com extensões cpp,. h e. XAML\) do seu projeto Windows 8.1 na mesma pasta do arquivo de projeto \(. vcxproj\) para o projeto que você criou na etapa 1. Não copie o arquivo Package. appxmanifest e se você tiver um código separado para a área de trabalho do Windows 8.1 e telefone, escolha um da porta primeiro \(você precisará fazer algum trabalho mais tarde para adaptar\-se a outro\). Certifique\-se de copiar e subpastas e seu conteúdo. Se solicitado, escolha substituir todos os arquivos com nomes duplicados.  
  
6.  Reabra a solução e escolha **Adicionar, o Item existente** no menu de atalho para o nó do projeto. Selecione todos os arquivos copiados, exceto os que já fazem parte do projeto.  
  
     Verifique todas as subpastas e certifique\-se de adicionar os arquivos neles também.  
  
7.  Se você não estiver usando o mesmo nome do projeto como seu projeto anterior, abra o arquivo Package. appxmanifest e atualizar o ponto de entrada para refletir o nome do namespace para a classe de aplicativo.  
  
     O **ponto de entrada** campo atualizarei o arquivo contém um nome de escopo para a classe de aplicativo, que inclui o namespace que contém a classe do aplicativo. Quando você cria um projeto Universal do Windows, o namespace é definido como o nome do projeto. Se isso for diferente do que está nos arquivos copiados em seu projeto antigo, você deve atualizar um ou outro para torná\-los a corresponder.  
  
8.  Compile o projeto e resolva os erros de compilação devido às últimas alterações entre as diferentes versões do SDK do Windows.  
  
9. Execute o projeto na área de trabalho Local. Verifique se que não há nenhum erro de implantação e que o layout do aplicativo parece razoável e se ele funciona corretamente na área de trabalho.  
  
10. Se você tiver arquivos de código separados e. XAML para outro dispositivo, como Windows Phone 8.1, examinar esse código e identificar onde ele difere do dispositivo padrão. Se a diferença for apenas no layout, você poderá usar um Gerenciador de estado Visual no xaml para personalizar a exibição, dependendo do tamanho da tela. Para outras diferenças, você pode usar seções de condições no seu código usando as seguintes instruções de \#if.  
  
    ```  
    #if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_PC_APP) #if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_PHONE_APP) #if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP) #if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)  
    ```  
  
     Essas instruções respectivamente se aplicam a aplicativos da Windows Store, Windows Phone Store apps, ambos ou nenhum \(clássico Win32 somente desktop\). Essas macros só estão disponíveis no SDK do Windows 8.1 e posterior, portanto se seu código precisa ser compilado com versões anteriores do SDK do Windows ou para outras plataformas além do Windows, em seguida, você também deve considerar o caso que nenhuma delas são definidas.  
  
11. Executar e depurar o aplicativo em um emulador ou um dispositivo físico, para cada tipo de dispositivo que oferece suporte a seu aplicativo. Para executar um emulador, você precisa executar o Visual Studio em um computador físico, não uma máquina virtual.  
  
##  <a name="BK_81Component"></a> Portabilidade de um componente de tempo de execução do Windows 8.1 para o UWP  
 Se você tiver uma DLL ou um componente de tempo de execução do Windows já funciona com aplicativos do Windows 8.1 Store, você pode usar este procedimento para obter o componente ou DLL trabalhando com UWP e Windows 10. O procedimento básico é criar um novo projeto e copie seu código para ela.  
  
#### A porta de um componente de tempo de execução do Windows 8.1 para o UWP  
  
1.  No **novo projeto** caixa de diálogo no [!INCLUDE[vs_dev14](../mfc/includes/vs_dev14_md.md)], localize o **Windows Universal** nó. Se você não vir esse nó, instale o [Ferramentas para Windows 10](http://go.microsoft.com/fwlink/p/?LinkID=617903) primeiro. Escolha o **o componente de tempo de execução do Windows** modelo, dê um nome para seu componente e escolha o **OK** botão. O nome do componente será ser usado como o nome do namespace, para que você talvez queira usar o mesmo nome como o namespace do seu projeto antigo. Isso requer que você crie o projeto em uma pasta diferente da antiga. Se você escolher um nome diferente, você pode atualizar o nome do namespace nos arquivos de código gerado.  
  
2.  Feche o projeto.  
  
3.  Copie todos os arquivos de código \(. cpp,. h,. XAML, etc.\) o componente Windows 8.1 em seu projeto recém\-criado. Não copie o arquivo Package. appxmanifest.  
  
4.  Compile e resolva quaisquer erros devido a alterações entre versões diferentes do Windows SDK significativas.  
  
## Solução de problemas  
 Você pode encontrar vários erros durante o processo de mover o código para a plataforma Windows Universal. Aqui estão alguns dos problemas possíveis que podem ser encontrados.  
  
 **Problemas de configuração de projeto**  
  
 Você pode receber o erro:  
  
```Output  
não foi possível encontrar o assembly 'Platform. winmd': especifique o caminho de pesquisa de assembly usando /AI ou definindo a variável de ambiente LIBPATH  
```  
  
 Se isso acontecer, o projeto não está criando um projeto Universal do Windows. Verifique o arquivo de projeto e verifique se que ele tem os elementos XML corretos que identificam um projeto como um projeto Universal do Windows. Os elementos a seguir devem estar presentes \(o número de versão da plataforma de destino pode ser diferente\):  
  
```xml  
<AppContainerApplication>true</AppContainerApplication> <ApplicationType>Windows Store</ApplicationType> <WindowsTargetPlatformVersion>10.0.10156.0</WindowsTargetPlatformVersion> <WindowsTargetPlatformMinVersion>10.0.10156.0</WindowsTargetPlatformMinVersion> <ApplicationTypeRevision>10.0</ApplicationTypeRevision>  
```  
  
 Se você criou um novo projeto de plataforma Universal do Windows usando o Visual Studio, você não verá esse erro.  
  
## Consulte também  
 [Visual C\+\+ Porting Guide](../porting/porting-to-the-universal-windows-platform-cpp.md)   
 [Desenvolva aplicativos para a plataforma Windows Universal \(UWP\)](../Topic/Develop%20apps%20for%20the%20Universal%20Windows%20Platform%20\(UWP\).md)