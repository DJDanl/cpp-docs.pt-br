---
title: Avisos de compilador desativados por padrão
ms.date: 05/30/2018
helpviewer_keywords:
- warnings, compiler
- cl.exe compiler, setting options
ms.assetid: 69809cfb-a38a-4035-b154-283a61938df8
ms.openlocfilehash: ee2b6097a62a8f1030dc631354f96ec7a33d2f11
ms.sourcegitcommit: 72583d30170d6ef29ea5c6848dc00169f2c909aa
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/18/2019
ms.locfileid: "59039391"
---
# <a name="compiler-warnings-that-are-off-by-default"></a>Avisos do compilador que são desativados por padrão

O compilador suporta os avisos que são desativados por padrão, porque a maioria dos desenvolvedores não sejam úteis. Em alguns casos, eles avisam sobre uma opção estilísticas ou sobre linguagens comuns no código mais antigo. Outros avisos são sobre o uso de uma extensão da Microsoft para o idioma. Em outros casos, elas indicam uma área em que os programadores geralmente fazem suposições incorretas, que podem resultar em comportamento inesperado ou indefinido. Se habilitada, alguns desses avisos podem aparecer várias vezes nos cabeçalhos da biblioteca. As bibliotecas de tempo de execução do C e as bibliotecas padrão do C++ são destinadas para não emitir nenhum aviso somente no nível de aviso [/W4](../build/reference/compiler-option-warning-level.md).

## <a name="enable-warnings-that-are-off-by-default"></a>Habilitar os avisos são desativados por padrão

Você pode habilitar os avisos que são normalmente desativados por padrão, usando uma das seguintes opções:

- **Aviso #pragma (padrão:** *warning_number* **)**

   O aviso especificado (*warning_number*) está habilitado no seu nível padrão. A documentação para o aviso contém o nível padrão do aviso.

- **#pragma warning(** *warning_level* **:** *warning_number* **)**

   O aviso especificado (*warning_number*) está habilitado no nível especificado (*warning_level*).

- [/Wall](../build/reference/compiler-option-warning-level.md)

   `/Wall` habilita todos os avisos que são desativados por padrão. Se você usar essa opção, você pode desativar avisos individuais usando o [/wd](../build/reference/compiler-option-warning-level.md) opção.

- [/w*Lnnnn*](../build/reference/compiler-option-warning-level.md)

   Essa opção permite que o aviso *nnnn* no nível *L*.

## <a name="warnings-that-are-off-by-default"></a>Avisos são desativados por padrão

Os seguintes avisos são desativados por padrão no Visual Studio 2015 e versões posteriores:

|||
|-|-|
|[C4061](../error-messages/compiler-warnings/compiler-warning-level-4-c4061.md) (nível 4)|enumerador '*identificador*'em um switch de enumeração'*enumeração*' não é manipulado explicitamente por um rótulo case|
|[C4062](../error-messages/compiler-warnings/compiler-warning-level-4-c4062.md) (nível 4)|enumerador '*identificador*'em um switch de enumeração'*enumeração*' não é tratado|
| [C4165](../error-messages/compiler-warnings/compiler-warning-level-1-c4165.md) (nível 1) | 'HRESULT' está sendo convertido em 'bool'; Tem certeza de que é isso que você deseja? |
| [C4191](../error-messages/compiler-warnings/compiler-warning-level-3-c4191.md) (level 3)|'*operador*': conversão não segura de '*type_of_expression*'para'*type_required*'|
|[C4242](../error-messages/compiler-warnings/compiler-warning-level-4-c4242.md) (nível 4)|'*identificador*': conversão de '*type1*'para'*type2*', possível perda de dados|
|[C4254](../error-messages/compiler-warnings/compiler-warning-level-4-c4254.md) (nível 4)|'*operador*': conversão de '*type1*'para'*type2*', possível perda de dados|
|[C4255](../error-messages/compiler-warnings/compiler-warning-level-4-c4255.md) (nível 4)|'*função*': nenhum protótipo de função fornecido: convertendo '()' para '(void)'|
|[C4263](../error-messages/compiler-warnings/compiler-warning-level-4-c4263.md) (nível 4)|'*função*': função de membro não substitui nenhuma função de membro virtual da classe base|
|[C4264](../error-messages/compiler-warnings/compiler-warning-level-1-c4264.md) (nível 1)|'*virtual_function*': nenhuma substituição disponível para função membro virtual da Base de dados de '*classe*'; função é ocultada|
|[C4265](../error-messages/compiler-warnings/compiler-warning-level-3-c4265.md) (nível 3)|'*classe*': classe possui funções virtual, mas não o destruidor é virtual|
|[C4266](../error-messages/compiler-warnings/compiler-warning-level-4-c4266.md) (nível 4)|'*função*': nenhuma substituição disponível para função membro virtual da Base de dados de '*tipo*'; função é ocultada|
|[C4287](../error-messages/compiler-warnings/compiler-warning-level-3-c4287.md) (nível 3)|'*operador*': incompatibilidade de constante unsigned/negativa|
|[C4289](../error-messages/compiler-warnings/compiler-warning-level-4-c4289.md) (nível 4)|extensão não padrão usada: '*var*': variável de controle de loop declarada no loop for é usada fora do escopo de loop for|
|[C4296](../error-messages/compiler-warnings/compiler-warning-level-4-c4296.md) (nível 4)|'*operador*': expressão sempre é false|
|[C4339](../error-messages/compiler-warnings/compiler-warning-level-4-c4339.md) (nível 4)|'*tipo*': uso de tipo indefinido detectado em metadados CLR - uso desse tipo pode levar a uma exceção de tempo de execução|
|[C4342](../error-messages/compiler-warnings/compiler-warning-level-1-c4342.md) (nível 1)|alteração de comportamento: '*função*' chamado, mas um operador de membro foi chamado em versões anteriores|
|[C4350](../error-messages/compiler-warnings/compiler-warning-level-1-c4350.md) (nível 1)|alteração de comportamento: '*member1*'chamado em vez de'*membro2*'|
|[C4355](../error-messages/compiler-warnings/compiler-warning-c4355.md)|'this' : usado na lista de inicializadores do membro base|
|[C4365](../error-messages/compiler-warnings/compiler-warning-level-4-c4365.md) (nível 4)|'*ação*': conversão de '*type_1*'para'*type_2*', incompatibilidade de signed/unsigned|
|C4370 (nível 3)|layout da classe foi alterado de uma versão anterior do compilador devido a empacotamento melhor|
|[C4371](../error-messages/compiler-warnings/c4371.md) (nível 3)|'*classname*': layout da classe pode ter alterado de uma versão anterior do compilador devido a empacotamento melhor do membro '*membro*'|
|C4388 (nível 4)|incompatibilidade de signed/unsigned|
|[C4412](../error-messages/compiler-warnings/compiler-warning-level-2-c4412.md) (nível 2)|'*função*': assinatura de função contém o tipo '*tipo*'; Objetos de C++ são seguros para passar entre código puro e combinado ou nativo|
|C4426 (nível 1)|os sinalizadores de otimização foram alterados após incluir o cabeçalho, pode ser devido a #pragma Optimize () <sup>14,1</sup>|
|[C4435](../error-messages/compiler-warnings/compiler-warning-level-4-c4435.md) (nível 4)|'*class1*': Layout do objeto em/vd2 será alterado devido à base virtual '*class2*'|
|[C4437](../error-messages/compiler-warnings/compiler-warning-level-4-c4437.md) (nível 4)|dynamic_cast da base virtual '*class1*'para'*class2*' poderia falhar em alguns contextos|
|C4444 (nível 3)|top level '__unaligned' não é implementado nesse contexto|
|[C4464](../error-messages/compiler-warnings/c4464.md) (nível 4)|caminho de inclusão relativo contém '.. '|
|[C4471](../error-messages/compiler-warnings/compiler-warning-level-4-c4471.md) (nível 4)|uma declaração de encaminhamento de uma enumeração sem escopo deve ter um tipo subjacente (int assumido) <sup>Perm</sup>|
|C4472 (nível 1)|'*identificador*' é uma enumeração nativa: adicionar um especificador de acesso (pública/privada) para declarar um enum gerenciado|
|[C4514](../error-messages/compiler-warnings/compiler-warning-level-4-c4514.md) (nível 4)|'*função*': função inline não referenciada foi removida|
|[C4536](../error-messages/compiler-warnings/compiler-warning-level-4-c4536.md) (nível 4)|'type name': nome do tipo excede o limite de metadados de '*limite*' caracteres|
|[C4545](../error-messages/compiler-warnings/compiler-warning-level-1-c4545.md) (nível 1)|expressão antes da vírgula é avaliada para uma função que está ausente em uma lista de argumentos|
|[C4546](../error-messages/compiler-warnings/compiler-warning-level-1-c4546.md) (nível 1)|faltando lista de argumentos na chamada de função antes da vírgula|
|[C4547](../error-messages/compiler-warnings/compiler-warning-level-1-c4547.md) (nível 1)|'*operador*': operador antes da vírgula não tem nenhum efeito; esperado operador com efeito colateral|
|[C4548](../error-messages/compiler-warnings/compiler-warning-level-1-c4548.md) (nível 1)|expressão antes da vírgula não tem efeito; expressão esperada com efeito colateral|
|[C4549](../error-messages/compiler-warnings/compiler-warning-level-1-c4549.md) (nível 1)|'*operator1*': operador antes da vírgula não tem nenhum efeito; você pretendia '*operator2*'?|
|[C4555](../error-messages/compiler-warnings/compiler-warning-level-1-c4555.md) (nível 1)|expressão não tem efeito; expressão esperada com efeito colateral|
|[C4557](../error-messages/compiler-warnings/compiler-warning-level-3-c4557.md) (nível 3)|assume' contém efeito '*efeito*'|
|[C4571](../error-messages/compiler-warnings/compiler-warning-level-4-c4571.md) (nível 4)|Informativo: semântica catch alterada desde o Visual C++ 7.1; exceções estruturadas (SEH) não são mais capturadas|
|C4574 (nível 4)|'*identificador*'é definido como ' 0': você pretendia usar ' #if *identificador*'?|
|C4577 (nível 1)|'noexcept' usado com nenhum modo especificado; de manipulação de exceção Não há garantia a terminação na exceção. Especifique /EHsc|
|C4582 (nível 4)|'*tipo*': construtor não está chamado implicitamente|
|C4583 (nível 4)|'*tipo*': destruidor não é chamado implicitamente|
|C4587 (nível 1)|'*anonymous_structure*': alteração de comportamento: construtor é não é mais implicitamente chamado|
|C4588 (nível 1)|'*anonymous_structure*': alteração de comportamento: destruidor é não é mais implicitamente chamado|
|C4596 (nível 4)|'*identificador*': nome qualificado inválido na declaração de membro <sup>14,3</sup> <sup>Perm</sup>|
|C4598 (nível 1 e nível 3)|' #include "*cabeçalho*"': o número de cabeçalho *número* no cabeçalho pré-compilado não coincide com a compilação atual nessa posição <sup>14,3</sup>|
|C4599 (nível 3)|'*opção* *caminho*': o número de argumento de linha de comando *número* não corresponde ao cabeçalho pré-compilado <sup>14,3</sup>|
|C4605 (nível 1)|' /D*macro*' especificado na linha de comando atual, mas não foi especificado quando o cabeçalho pré-compilado foi criado|
|[C4608](../error-messages/compiler-warnings/compiler-warning-level-3-c4608.md) (nível 3)|'*union_member*'já foi inicializado por outro membro de união na lista de inicializadores,'*union_member*' <sup>Perm</sup>|
|[C4619](../error-messages/compiler-warnings/compiler-warning-level-3-c4619.md) (nível 3)|Aviso #pragma: há um número de aviso '*número*'|
|[C4623](../error-messages/compiler-warnings/compiler-warning-level-4-c4623.md) (nível 4)|'derived class': construtor padrão não pôde ser gerado porque o construtor padrão de uma classe base está inacessível|
|[C4625](../error-messages/compiler-warnings/compiler-warning-level-4-c4625.md) (nível 4)|'derived class': construtor de cópia não pôde ser gerado porque o construtor de cópia de uma classe base está inacessível|
|[C4626](../error-messages/compiler-warnings/compiler-warning-level-4-c4626.md) (nível 4)|'derived class': operador de atribuição não pôde ser gerado porque o operador de atribuição de uma classe base está inacessível|
|[C4628](../error-messages/compiler-warnings/compiler-warning-level-1-c4628.md) (nível 1)|dígrafos não suportados com -Ze. Sequência de caracteres '*dígrafo*'não é interpretada como token alternativo para'*char*'|
|[C4640](../error-messages/compiler-warnings/compiler-warning-level-3-c4640.md) (nível 3)|'*instância*': construção de objeto estático local não é thread-safe|
| C4643 (nível 4) | Encaminhar declarando '*identificador*' no namespace std não é permitido pelo padrão C++. <sup>15.8</sup> |
|C4647 (nível 3)|alteração de comportamento: is_pod (*tipo*) tem um valor diferente em versões anteriores|
|C4654 (nível 4)|O código colocado antes de incluir de cabeçalho pré-compilado linha será ignorada. Adicione código ao cabeçalho pré-compilado. <sup>14.1</sup>|
|[C4668](../error-messages/compiler-warnings/compiler-warning-level-4-c4668.md) (nível 4)|'*símbolo*'não está definido como uma macro de pré-processador, substituindo por '0' para'*diretivas*'|
|[C4682](../error-messages/compiler-warnings/compiler-warning-level-4-c4682.md) (nível 4)|'*símbolo*': nenhum atributo de parâmetro direcional especificado, padronizando para [in]|
|[C4686](../error-messages/compiler-warnings/compiler-warning-level-3-c4686.md) (nível 3)|'*tipo definido pelo usuário*': possível alteração no comportamento, alteração na UDT retorne a convenção de chamada|
|[C4692](../error-messages/compiler-warnings/compiler-warning-level-1-c4692.md) (nível 1)|'*função*': assinatura de membro não private contém tipo nativo private de assembly '*native_type*'|
|[C4710](../error-messages/compiler-warnings/compiler-warning-level-4-c4710.md) (nível 4)|'*função*': função não embutida|
|[C4738](../error-messages/compiler-warnings/compiler-warning-level-3-c4738.md) (nível 3)|armazenando o resultado float de 32 bits na memória, possível perda de desempenho|
|[C4746](../error-messages/compiler-warnings/compiler-warning-c4746.md)|acesso volátil de '*expressão*' está sujeito a /volatile:\<iso&#124;ms > Configuração; considere o uso de funções intrínsecas do iso_volatile_load/store|
|C4749 (nível 4)|tem suporte condicionalmente: offsetof aplicado ao tipo de layout não padrão '*tipo*'|
|C4767 (nível 4)|nome da seção '*símbolo*' tem mais de 8 caracteres e será truncado pelo vinculador|
|C4768 (nível 3)|atributos de declspec antes da especificação de vinculação são ignorados|
|C4774 (nível 4)|'*cadeia de caracteres*': Formatar a cadeia de caracteres esperada no argumento *número* não é uma cadeia de caracteres literal|
|C4777 (nível 4)|'*função*': cadeia de caracteres de formato '*cadeia de caracteres*'requer um argumento do tipo'*type1*', mas o argumento variadic *número* tem o tipo '*type2*'|
|C4786 (nível 3)|'*símbolo*': nome do objeto foi truncado para '*número*' caracteres nas informações de depuração|
| [C4800](../error-messages/compiler-warnings/compiler-warning-level-3-c4800.md) (nível 4) | Conversão implícita de '*tipo*' em bool. Possível perda de informações <sup>16.0</sup> |
|[C4820](../error-messages/compiler-warnings/compiler-warning-level-4-c4820.md) (nível 4)|'*bytes*'bytes de preenchimento adicionados após o constructo'*member_name*'|
| [C4822](../error-messages/compiler-warnings/compiler-warning-level-1-c4822.md) (nível 1) | '*membro*': função de membro de classe local não tem um corpo |
|C4826 (nível 2)|Conversão de '*type1*'para'*type2*' é estendido com sinal. Isso pode causar um comportamento inesperado de tempo de execução.|
|C4837 (nível 4)|trígrafo detectado: '?? *caractere*'substituído por'*caractere*'|
|C4841 (nível 4)|extensão não padrão usada: designador de membro composto usado no offsetof|
|C4842 (nível 4)|o resultado de 'offsetof' aplicado a um tipo usando a herança múltipla não é garantido para ser consistente entre versões do compilador|
|[C4868](../error-messages/compiler-warnings/compiler-warning-c4868.md) (level 4)|'_arquivo_(*line_number*)' compilador não pode impor a ordem de avaliação da esquerda para a direita na lista de inicialização entre chaves|
|[C4905](../error-messages/compiler-warnings/compiler-warning-level-1-c4905.md) (nível 1)|literal amplo de cadeia de caracteres convertido em 'LPSTR'|
|[C4906](../error-messages/compiler-warnings/compiler-warning-level-1-c4906.md) (nível 1)|literal de cadeia de caracteres convertido em 'LPWSTR'|
|[C4917](../error-messages/compiler-warnings/compiler-warning-level-1-c4917.md) (nível 1)|'*declarador*': um GUID só pode ser associado uma classe, interface ou namespace|
|[C4928](../error-messages/compiler-warnings/compiler-warning-level-1-c4928.md) (nível 1)|inicialização de cópia ilegal; mais de uma conversão definida pelo usuário foi implicitamente aplicada|
|[C4931](../error-messages/compiler-warnings/compiler-warning-level-4-c4931.md) (nível 4)|estamos supondo que a biblioteca de tipos foi criada para ponteiros de bit por número|
|[C4946](../error-messages/compiler-warnings/compiler-warning-level-1-c4946.md) (nível 1)|reinterpret_cast usado entre classes relacionadas: '*class1*'e'*class2*'|
|C4962|'*função*': otimizações guiadas por perfil desabilitadas porque otimizações fizeram dados de perfil se tornar inconsistente|
|[C4986](../error-messages/compiler-warnings/compiler-warning-c4986.md) (nível 4)|'*símbolo*': especificação de exceção não corresponde à declaração anterior|
|C4987 (nível 4)|extensão não padrão usada: 'throw (...)'|
|C4988 (nível 4)|'*símbolo*': variável declarada fora do escopo de classe/função|
|C5022|'*tipo*': vários construtores de movimento especificados|
|C5023|'*tipo*': vários operadores de atribuição de movimento especificados|
|C5024 (nível 4)|'*tipo*': construtor de movimento foi implicitamente definido como excluído|
|C5025 (nível 4)|'*tipo*': mover operador de atribuição foi implicitamente definido como excluído|
|C5026 (nível 1 e nível 4)|'*tipo*': construtor de movimento foi implicitamente definido como excluído|
|C5027 (nível 1 e nível 4)|'*tipo*': mover operador de atribuição foi implicitamente definido como excluído|
|C5029 (nível 4)|extensão não padrão usada: atributos de alinhamento no C++ se aplicam a variáveis, membros de dados e somente os tipos de marcas|
|C5031 (nível 4)|Warning (POP) #pragma: provável incompatibilidade, estado de aviso enviado por push em outro arquivo mostrado <sup>14,1</sup>|
|C5032 (nível 4)|detectado Warning (push) com nenhum correspondente Warning (POP) #pragma #pragma <sup>14,1</sup>|
|C5034|Use intrínseco '*intrínseco*' faz com que a função *função* seja compilada como código de convidado <sup>15.3</sup>|
|C5035|usar o recurso '*recurso*' faz com que a função *função* seja compilada como código de convidado <sup>15.3</sup>|
|C5036 (nível 1)|conversão de ponteiro de função varargs ao compilar com/Hybrid:x86arm64 '*type1*'para'*type2*' <sup>15.3</sup>|
|[C5038](../error-messages/compiler-warnings/c5038.md) (nível 4)|membro de dados '*member1*'será inicializados após o membro de dados'*membro2*' <sup>15.3</sup>|
|C5039 (nível 4)|'*função*': ponteiro ou referência a função potencialmente lançada passada para a função C externa em - EHc. Um comportamento indefinido pode ocorrer se essa função gera uma exceção. <sup>15.5</sup>|
|C5042 (nível 3)|'*função*': declarações de função no escopo de bloco não podem ser especificado 'inline' em C++ padrão; remova o especificador "embutido" <sup>15.5</sup>|
|[C5045](../error-messages/compiler-warnings/c5045.md)|Compilador inserirá a mitigação de espectro para carga de memória se a opção /Qspectre especificada <sup>15.7</sup>|

<sup>14,1</sup> esse aviso está disponível a partir do Visual Studio 2015 atualização 1.<br/>
<sup>14,3</sup> esse aviso está disponível a partir do Visual Studio 2015 atualização 3.<br/>
<sup>15.3</sup> esse aviso está disponível a partir do Visual Studio 2017 versão 15.3.<br/>
<sup>15.5</sup> esse aviso está disponível a partir do Visual Studio 2017 versão 15.5.<br/>
<sup>15.7</sup> esse aviso está disponível a partir do Visual Studio 2017 versão 15.7.<br/>
<sup>15,8</sup> esse aviso está disponível a partir do Visual Studio 2017 versão 15,8.<br/>
::: moniker range=">= vs-2019"
<sup>16.0</sup> esse aviso está disponível a partir do Visual Studio 2019 RTM.<br/>
::: moniker-end
<sup>Perm</sup> esse aviso é desativado, a menos que o [/permissive--](../build/reference/permissive-standards-conformance.md) é definir a opção de compilador.<br/>

## <a name="warnings-off-by-default-in-earlier-versions"></a>Avisos desativado por padrão em versões anteriores

Esses avisos foram desativado por padrão em versões do compilador antes do Visual Studio 2015:

|||
|-|-|
|[C4302](../error-messages/compiler-warnings/compiler-warning-level-2-c4302.md) (nível 2)|'*conversão*': truncamento de '*type1*'para'*type2*'|
|[C4311](../error-messages/compiler-warnings/compiler-warning-level-1-c4311.md) (nível 1)|'*variável*': truncamento de ponteiro de '*tipo*'para'*tipo*'|
|[C4312](../error-messages/compiler-warnings/compiler-warning-level-1-c4312.md) (nível 1)|'*operação*': conversão de '*type1*'para'*type2*' de tamanho maior|
|[C4319](../error-messages/compiler-warnings/compiler-warning-level-1-c4319.md) (nível 1)|'*operador*': estendendo o zero '*type1*'para'*type2*' de tamanho maior|

Esse aviso era desativado por padrão nas versões do compilador antes do Visual Studio 2012:

|||
|-|-|
|[C4431](../error-messages/compiler-warnings/compiler-warning-level-4-c4431.md) (nível 4)|faltando especificador de tipo - int assumido. Observação: C não suporta default-int|

## <a name="see-also"></a>Consulte também

[warning](../preprocessor/warning.md)