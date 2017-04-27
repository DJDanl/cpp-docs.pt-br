---
title: C4800 de avisos do compilador por meio de C4999 | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C4806
- C4807
- C4810
- C4811
- C4812
- C4813
- C4816
- C4817
- C4822
- C4825
- C4827
- C4872
- C4880
- C4881
- C4882
- C4900
- C4910
- C4912
- C4913
- C4916
- C4918
- C4920
- C4921
- C4925
- C4926
- C4932
- C4934
- C4935
- C4936
- C4937
- C4938
- C4939
- C4944
- C4947
- C4950
- C4951
- C4952
- C4953
- C4954
- C4955
- C4956
- C4957
- C4958
- C4959
- C4960
- C4961
- C4962
- C4963
- C4966
- C4970
- C4971
- C4972
- C4973
- C4974
- C4981
- C4985
- C4987
- C4988
- C4989
- C4990
- C4991
- C4992
- C4997
- C4998
- C4999
- C4808
- C4809
dev_langs:
- C++
ms.assetid: c3182430-8b3b-4ab2-a532-5cd436707dc8
caps.latest.revision: 9
author: corob-msft
ms.author: corob
manager: ghogen
translation.priority.mt:
- cs-cz
- pl-pl
- pt-br
- tr-tr
translationtype: Machine Translation
ms.sourcegitcommit: 4bac7b2942f9d72674b8092dc7bf64174dd3c349
ms.openlocfilehash: ac03a99c1a9413b697b6e40101bf1c3e2be9a3a6
ms.lasthandoff: 04/24/2017

---
# <a name="compiler-warnings-c4800-through-c4999"></a>C4800 de avisos do compilador por meio de C4999
Os artigos desta parte da documentação contém informações sobre um subconjunto de avisos do compilador do Visual C++. Você pode acessar as informações aqui ou, na janela de saída no Visual Studio, você pode selecionar um número de erro e, em seguida, pressione a tecla F1.  
  
> [!NOTE]
>  Nem todo [!INCLUDE[vcprvc](../../build/includes/vcprvc_md.md)] erro ou aviso é documentado no MSDN. Em muitos casos, a mensagem de diagnóstica fornece todas as informações que estão disponíveis. Se você achar que precisa de uma mensagem de erro explicação adicional, você poderá nos informar. Use o formulário de comentários nesta página, ou vá para a barra de menus do Visual Studio e escolha **ajuda**, **relatar um erro**, ou você pode enviar um relatório de sugestão ou um bug em [Microsoft Connect](http://connect.microsoft.com/VisualStudio).  
  
Você pode obter assistência adicional para erros e avisos nos fóruns públicos do MSDN. O [linguagem Visual C++](http://go.microsoft.com/fwlink/?LinkId=158195) fórum é para perguntas e discussões sobre o [!INCLUDE[vcprvc](../../build/includes/vcprvc_md.md)] sintaxe de linguagem e compilador. O [geral do Visual C++](http://go.microsoft.com/fwlink/?LinkId=158194) fórum é para perguntas sobre [!INCLUDE[vcprvc](../../build/includes/vcprvc_md.md)] que não são abordados em outros fóruns. Você também pode encontrar ajuda sobre erros e avisos sobre [estouro de pilha](http://stackoverflow.com/).  
  
## <a name="in-this-section"></a>Nesta seção  
  
|Aviso|Mensagem|  
|-------------|-------------|  
|[Aviso do compilador (nível 3) C4800](../../error-messages/compiler-warnings/compiler-warning-level-3-c4800.md)|'type': forçando valor para bool 'true' ou 'false' (aviso de desempenho)|  
|[Aviso do compilador (nível 1) C4803](../../error-messages/compiler-warnings/compiler-warning-level-1-c4803.md)|'method': o método raise possui uma classe de armazenamento diferente do evento, 'event'|  
|[Aviso do compilador (nível 1) C4804](../../error-messages/compiler-warnings/compiler-warning-level-1-c4804.md)|'operação de ': uso não seguro de tipo 'bool' em operação|  
|[Aviso do compilador (nível 1) C4805](../../error-messages/compiler-warnings/compiler-warning-level-1-c4805.md)|'operação de ': mistura não segura de tipo 'type' e tipo 'type' em operação|  
|Aviso do compilador (nível 1) C4806|'operação de ': operação não segura: nenhum valor de tipo 'type' promovido para o tipo 'type' pode ser igual à constante fornecida|  
|Aviso do compilador (nível 1) C4807|'operação de ': mistura não segura de tipo 'type' e o campo de bit com sinal do tipo 'type'|  
|Aviso do compilador (nível 1) C4808|Caso 'value' não é um valor válido para a condição de switch de tipo 'bool'|  
|Aviso do compilador (nível 1) C4809|instrução switch possui rótulo 'default' redundante; todos os rótulos 'case' possíveis são fornecidos|  
|Aviso do compilador (nível 1) C4810|valor de pragma Pack (show) o usuário = = n|  
|Aviso do compilador (nível 1) C4811|valor de pragma conform (forScope, show) = = valor|  
|Aviso do compilador (nível 1) C4812|estilo de declaração obsoleta: use 'new_syntax' em vez disso|  
|Aviso do compilador (nível 1) C4813|'function': uma função friend de uma classe local deve ter sido anteriormente declarada|  
|Aviso do compilador (nível 4) C4816|'param': parâmetro possui uma matriz de tamanho zero que será truncada (a menos que o objeto é passado por referência)|  
|Aviso do compilador (nível 1) C4817|'member': uso inválido de '.' para acessar este membro; compilador substituiu por '->'|  
|[Aviso do compilador (nível 1) C4819](../../error-messages/compiler-warnings/compiler-warning-level-1-c4819.md)|O arquivo contém um caractere que não pode ser representado na página de código atual (número). Salve o arquivo em formato Unicode para evitar perda de dados|  
|[Aviso do compilador (nível 4) C4820](../../error-messages/compiler-warnings/compiler-warning-level-4-c4820.md)|preenchimento de bytes 'bytes' adicionado após construção de 'member_name'|  
|[Aviso do compilador (nível 1) C4821](../../error-messages/compiler-warnings/compiler-warning-level-1-c4821.md)|Não é possível determinar tipo de codificação Unicode, salve o arquivo com assinatura (BOM)|  
|Aviso do compilador (nível 1) C4822|'função de membro': função de membro de classe local não tem um corpo|  
|[Aviso do compilador (nível 3) C4823](../../error-messages/compiler-warnings/compiler-warning-level-3-c4823.md)|'function': usa ponteiros de fixação mas desenrolar semântica não está habilitada. Considere o uso de /EHa|  
|Aviso do compilador (nível 4) C4825||  
|Aviso do compilador (nível 3) C4827|Um método 'ToString' público com 0 parâmetro deve ser marcado como virtual e override|  
|[Aviso do compilador (nível 1) C4829](../../error-messages/compiler-warnings/compiler-warning-level-1-c4829.md)|Parâmetros possivelmente incorretos para a função principal. Considere a possibilidade de ' int principal (Platform:: array\<Platform:: String ^ > ^ argv)'|  
|[Aviso do compilador (nível 1) C4835](../../error-messages/compiler-warnings/compiler-warning-level-1-c4835.md)|'variável': o inicializador para dados exportados não será executado até que o código gerenciado é executado pela primeira vez no host assembly|  
|[Aviso do compilador (nível 1) C4838](../../error-messages/compiler-warnings/compiler-warning-level-1-c4838.md)|conversão de 'type_1' em 'type_2' requer uma conversão de restrição|  
|[Aviso do compilador C4867](../../error-messages/compiler-warnings/compiler-warning-c4867.md)|'function': chamada de função faltando lista de argumentos; Use 'chamar' para criar um ponteiro para membro|  
|[Aviso do compilador C4868](../../error-messages/compiler-warnings/compiler-warning-c4868.md)|compilador 'file(line_number)' não pode impor a ordem de avaliação da esquerda para a direita na lista de inicialização entre chaves|  
|Aviso do compilador (nível 2) C4872|divisão de ponto flutuante por zero detectada ao compilar o gráfico de chamada concurrency::parallel_for_each em: '%s'|  
|Aviso do compilador (nível 1) C4880|conversão de 'const type_1' em 'type_2': Rejeitando constness de um ponteiro ou referência pode resultar em comportamento indefinido em uma função de amp restringido|  
|Aviso do compilador (nível 4) C4881|o construtor e/ou o destruidor não será chamado para inicializar a variável tile_static 'variável'|  
|Aviso do compilador (nível 1) C4882|a transmissão de functors com operadores de chamada não constantes para concurrency::parallel_for_each foi preterida|  
|C4900 de aviso do compilador|Incompatibilidade de IL entre 'tool1' versão 'version1' e 'tool2' 'versão 2'|  
|[Aviso do compilador (nível 1) C4905](../../error-messages/compiler-warnings/compiler-warning-level-1-c4905.md)|literal amplo de cadeia de caracteres convertido em 'LPSTR'|  
|[Aviso do compilador (nível 1) C4906](../../error-messages/compiler-warnings/compiler-warning-level-1-c4906.md)|literal de cadeia de caracteres convertido em 'LPWSTR'|  
|Aviso do compilador (nível 1) C4910|'\<identificador >: 'dllexport' e 'extern' são incompatíveis em uma instanciação explícita|  
|Aviso do compilador (nível 1) C4912|'attribute': atributo possui comportamento indefinido em um UDT aninhado|  
|Aviso do compilador (nível 4) C4913|operador binário definido pelo usuário ',' existe mas nenhuma sobrecarga pôde converter todos os operando, operador binário interno padrão ',' usado|  
|Aviso do compilador (nível 1) C4916|a fim de possuir um dispid, '%$S': deve ser introduzido por uma interface|  
|[Aviso do compilador (nível 1) C4917](../../error-messages/compiler-warnings/compiler-warning-level-1-c4917.md)|'Declarador de ': um GUID só pode ser associado uma classe, interface ou namespace|  
|Aviso do compilador (nível 4) C4918|'character': caractere inválido na lista de otimização de pragma|  
|Aviso do compilador (nível 1) C4920|enumeração enum membro member_1 = value_1 já visto em enum de enum como member_2 = value_2|  
|Aviso do compilador (nível 3) C4921|'%s': valor de atributo '%s' não deve ser especificado várias vezes|  
|Aviso do compilador (nível 1) C4925|'method': método dispinterface não pode ser chamado do script|  
|Aviso do compilador (nível 1) C4926|'Identificador': símbolo já está definido: atributos ignorados|  
|[Aviso do compilador (nível 1) C4927](../../error-messages/compiler-warnings/compiler-warning-level-1-c4927.md)|conversão inválida; mais de uma conversão definida pelo usuário foi aplicada implicitamente|  
|[Aviso do compilador (nível 1) C4928](../../error-messages/compiler-warnings/compiler-warning-level-1-c4928.md)|inicialização de cópia ilegal; mais de uma conversão definida pelo usuário foi implicitamente aplicada|  
|[Aviso do compilador (nível 1) C4929](../../error-messages/compiler-warnings/compiler-warning-level-1-c4929.md)|'arquivo': biblioteca de tipos contém uma união; Ignorando o qualificador 'embedded_idl'|  
|[Aviso do compilador (nível 1) C4930](../../error-messages/compiler-warnings/compiler-warning-level-1-c4930.md)|'protótipo': função prototipada não chamada (era uma definição de variável se destina?)|  
|[Aviso do compilador (nível 4) C4931](../../error-messages/compiler-warnings/compiler-warning-level-4-c4931.md)|estamos supondo que a biblioteca de tipos foi criada para ponteiros de bit por número|  
|Aviso do compilador (nível 4) C4932|__identifier(Identifier) e \__identifier(identifier) são indistinguíveis|  
|Aviso do compilador (nível 1) C4934|'__delegate(multicast)' é preterido, use '\_delegate ' em vez disso|  
|Aviso do compilador (nível 1) C4935|especificador de acesso de assembly modificado de 'access'|  
|Aviso do compilador (nível 1) C4936|este __declspec é suportado apenas quando compilado com /clr ou com /clr:pure|  
|Aviso do compilador (nível 4) C4937|'text1' e 'text2' são indistinguíveis como argumentos para 'diretiva'|  
|Aviso do compilador (nível 4) C4938|'var': variável de redução de ponto flutuante pode causar resultados inconsistentes sob /fp: strict ou #pragma fenv_access|  
|C4939 de aviso do compilador|#pragma vtordisp é preterido e será removido em uma versão futura do Visual C++|  
|Aviso do compilador (nível 1) C4944|'symbol': não é possível importar símbolo de 'assembly1': como 'symbol' já existe no escopo atual|  
|[Aviso do compilador (nível 1) C4945](../../error-messages/compiler-warnings/compiler-warning-level-1-c4945.md)|'symbol': não é possível importar símbolo de 'assembly1': como 'symbol' já foi importado de outro assembly 'assembly2'|  
|[Aviso do compilador (nível 1) C4946](../../error-messages/compiler-warnings/compiler-warning-level-1-c4946.md)|reinterpret_cast usado entre classes relacionadas: 'class1' e 'class2'|  
|Aviso do compilador (nível 1) C4947|'type_or_member': marcado como obsoleto|  
|[Aviso do compilador (nível 2) C4948](../../error-messages/compiler-warnings/compiler-warning-level-2-c4948.md)|tipo de retorno de 'acessador' não coincide com o último tipo de parâmetro do setter correspondente|  
|[Aviso do compilador (níveis 1 e 4) C4949](../../error-messages/compiler-warnings/compiler-warning-level-1-and-level-4-c4949.md)|pragmas 'managed' e 'unmanaged' são significativos apenas quando compilado com ' / clr [: opção]'|  
|Aviso do compilador (nível 1) C4950|'type_or_member': marcado como obsoleto|  
|C4951 de aviso do compilador|'function' foi editado após os dados de perfil de função não usados coleta dados de perfil|  
|C4952 de aviso do compilador|'function': nenhum dado de perfil encontrado no banco de dados do programa 'pgd_file'|  
|C4953 de aviso do compilador|Embutido 'function' foi editado após os dados de perfil não usados coleta dados de perfil|  
|C4954 de aviso do compilador|'function': não analisado (contém expressão de switch Int64)|  
|C4955 de aviso do compilador|'import2': importação ignorada; já importado de 'import1'|  
|Aviso do compilador (nível 1) C4956|'type': este tipo não é verificável|  
|Aviso do compilador (nível 1) C4957|'cast': conversão explícita de 'conversão de' para 'cast_to' não é verificável|  
|Aviso do compilador (nível 1) C4958|'operação de ': aritmética de ponteiro não é verificável|  
|Aviso do compilador (nível 1) C4959|não é possível definir 'type' do tipo não gerenciado em /CLR: safe porque o acesso aos seus membros produz código não verificável|  
|C4960 de aviso do compilador|'function' é muito grande para ser analisado|  
|C4961 de aviso do compilador|Nenhum dado de perfil foi mesclado em 'arquivo de PGD', otimizações guiadas por perfil desabilitadas|  
|C4962 de aviso do compilador|'function': otimizações guiadas por perfil desabilitadas porque otimizações fizeram dados de perfil se tornar inconsistente|  
|C4963 de aviso do compilador|%s: nenhum dado de perfil encontrado; Opções do compilador diferentes foram usadas em compilação instrumentada|  
|[Aviso do compilador (nível 1) C4964](../../error-messages/compiler-warnings/compiler-warning-level-1-c4964.md)|Nenhuma opção de otimização foi especificada; informações de perfil não serão coletadas|  
|[Aviso do compilador (nível 1) C4965](../../error-messages/compiler-warnings/compiler-warning-level-1-c4965.md)|box implícito de inteiro 0; use nullptr ou conversão explícita|  
|C4966 de aviso do compilador|'%s' tem anotação __code_seg com o nome de segmento sem suporte, anotação ignorada|  
|C4970 de aviso do compilador|construtor delegate: objeto de destino ignorado porque '%$pS' é static|  
|Aviso do compilador (nível 1) C4971|Ordem de argumentos: \<o objeto de destino >, \<função de destino > para construtor delegate é preterida, use \<função de destino >, \<o objeto de destino = "" >|  
|Aviso do compilador (nível 1) C4972|Modificar diretamente ou tratar o resultado de uma operação de unbox como um lvalue não é verificável|  
|C4973 de aviso do compilador|'%$S': marcado como preterido|  
|C4974 de aviso do compilador|'%$S': marcado como preterido|  
|C4981 de aviso do compilador|Warbird: função '%$pD' marcada como __forceinline não embutida porque contém semântica de exceção|  
|Aviso do compilador (nível 3) C4985|nome do símbolo ': atributos não presentes em declaração anterior.|  
|[Aviso do compilador C4986](../../error-messages/compiler-warnings/compiler-warning-c4986.md)|'%$pS': especificação de exceção não corresponde à declaração anterior|  
|Aviso do compilador (nível 4) C4987|extensão não padrão usada: 'throw (...)'|  
|Aviso do compilador (nível 4) C4988|'%$S': variável declarada fora do escopo de classe/função|  
|C4989 de aviso do compilador|'%s': tipo tem definições conflitantes.|  
|C4990 de aviso do compilador|Warbird: %s|  
|C4991 de aviso do compilador|Warbird: função '%$pD' marcada como __forceinline não embutida porque o nível de proteção do item embutido é superior ao do pai|  
|C4992 de aviso do compilador|Warbird: função '%$pD' marcada como __forceinline não embutida porque contém assembly embutido que não pode ser protegido|  
|[Aviso do compilador (nível 3) C4995](../../error-messages/compiler-warnings/compiler-warning-level-3-c4995.md)|'function': nome foi marcado como #pragma preterido|  
|[Aviso do compilador (nível 3) C4996](../../error-messages/compiler-warnings/compiler-warning-level-3-c4996.md)|'%$pS': %$*|  
|Aviso do compilador (nível 1) C4997|'class': coclass não implementa uma interface COM ou pseudointerface|  
|Aviso do compilador (nível 1) C4998|FALHA NA EXPECTATIVA: %s(%d)|  
|C4999 de aviso do compilador|AVISO DESCONHECIDO %$N Escolha o comando de Suporte Técnico no menu de Ajuda do Visual C++, %$N ou abra o arquivo de ajuda do Suporte Técnico para mais informações|
