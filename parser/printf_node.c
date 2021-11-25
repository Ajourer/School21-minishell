# include "minishell.h"

void printf_node(t_all *all)
{
	t_all *tmp;
	tmp = all;
	int node_counter = 0;
	int i = 0;
	/*printf("%d\n", ft_strcmp("l", "l"));*/
	while (tmp)
	{
		printf("NODE n= %d REDIRs =%d ARGVs= %d INDEX PIPE=%d filename= %s TYPE_R= %d\n",\
				node_counter,\
				tmp->num_redir,\
				tmp->num_argv,\
				tmp->pipe,\
				tmp->redir ? tmp->redir[i].filename : 0,\
				tmp->redir ? tmp->redir[i].type_redir : 0);
		while (tmp->argv[i])
		{
			printf("%d)\t|\033[32m%s\033[0m|\n", i + 1, tmp->argv[i]);
			i++;
		}
		i = 0;
		node_counter++;
		tmp = tmp->next;
	}
}